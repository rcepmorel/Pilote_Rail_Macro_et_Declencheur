/*      Pilote_Rail_Macro_et_Declencheur
* 
* Auteur : Richard Morel
*     2019-02-05
* 
* Modification
*     
*     
* Remarques :     
* 
* Si l'application ne réussit pas à se connecter sur un réseau Wifi, 
* elle configurera le circuit comme un point d'accès réseau Wifi
* Son adresse IP sera alors 192.168.4.1.
* DEL : Vert -> brancher sur le réseau WiFi défini dans le programme
* DEL : Rouge -> Point d'accès WiFi
* 
* do_Web_1_Colonne.h -> Affichage plus adapté aux petits écrans 
*                       comme ceux des téléphones intelligents
* 
* do_Web_2_Colonnes.h -> Pour les autres dimensions d'écrans
* 
* 
*/  
// ----------------------------------------------------------------------------- 
//             Importation des fichiers et définition des variables
// ----------------------------------------------------------------------------- 
#include "configuration.h"
#include "do_Conversion_calcul.h"
#include "do_Commandes.h"

//******  WIFI *********************
#include "connect_id_Wifi.h"
#include <WiFi.h>
WiFiServer server(80);

const char* chStatusWifi[] ={"WL_IDLE_STATUS", "WL_NO_SSID_AVAIL", "-", 
                       "WL_CONNECTED ", "WL_CONNECT_FAILED ", "-",
                       "WL_DISCONNECTED"};

String stWifiConnectionNetwork = "Connecté";

//#include "do_Web_1_Colonne.h" // Affichage plus adapté aux petits écrans 
                                // comme ceux des téléphones intelligents
#include "do_Web_2_Colonnes.h"
#include "actions.h"

// -------------------------------------------------------------------------------
// FONCTION     FONCTION     FONCTION    FONCTION     FONCTION     FONCTION
// ------------------------------------------------------------------------------- 

//*****  Activation de la DEL   *****************
void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
  // calculate duty, 8191 from 2 ^ 13 - 1
  if (value > valueMax){value = valueMax;}
  uint32_t duty = (8191 / valueMax) * value;
  
  // write duty to LEDC
  ledcWrite(channel, duty);
}


//*****  Choix d'affichage de la couleur de la DEL *******
void AfficheVertCWRougePA(){
   if (stWifiConnectionNetwork=="Non connecté au réseau") {
      byBrightnessVert  = 0 ;
      byBrightnessRouge = 255 ;
      // set the brightness on LEDC channel 0
      ledcAnalogWrite(LEDC_CHANNEL_0_VERT, byBrightnessVert);
      // set the brightness on LEDC channel 1
      ledcAnalogWrite(LEDC_CHANNEL_1_ROUGE,byBrightnessRouge);
  }
  else  
  {
      byBrightnessVert  = 255;
      byBrightnessRouge = 0 ;
      ledcAnalogWrite(LEDC_CHANNEL_0_VERT, byBrightnessVert);
      ledcAnalogWrite(LEDC_CHANNEL_1_ROUGE,byBrightnessRouge);
  }
}


//*********** Exécution des commandes reçues *********
void do_ExecCommande(){ 
  if (boExecDeclencheApp){
     boExecDeclencheApp = false;
     strDirectionRef="";
     declencheApp();  
  }
  if (boExecAvanceLente){
     boExecAvanceLente = false;
     go_AvanceLente();  
     }    
  if (boExecAvanceRapide) {
     boExecAvanceRapide = false;
     go_AvanceRapide();     
  } 
  if (boExecAvanceTresRapide) {
     boExecAvanceTresRapide = false; 
     go_AvanceTresRapide(); 
  }       
  if (boExecStop) {
     boExecStop = false;
     compteur = intNbreDeBoucle;
     stop_Stop();  
  }
  if (boExecReculeLente) {
     boExecReculeLente = false;
     go_ReculeLente();    
  }    
  if (boExecReculeRapide) {
     boExecReculeRapide = false;
     go_ReculeRapide();   
  } 
  if (boExecReculeTresRapide) {
     boExecReculeTresRapide = false;
     go_ReculeTresRapide();   
  } 
  if (boExecRepereA) {
     boExecRepereA = false;
     intCompteurdePasRef = 0;
     strDirectionRef=""; 
  } 
  if (boExecRepereB) {
     boExecRepereB = false;
     strDirectionRef="";
  } 
  if (boExecAvanceCapture) {
     boExecAvanceCapture = false;
     go_AvanceCapture();  
  }
  if (boExecReculeCapture) {
     boExecReculeCapture = false;
     go_ReculeCapture();   
   }
}

// -------------------------------------------------------------------------------
// SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP
// ------------------------------------------------------------------------------- 
void setup() {
  Serial.begin(115200);
  Serial.println("INITIALISATION EN COURS");

  //**********  ENTRÉES - SORTIES *************
  pinMode( pinEnable8825,     OUTPUT );
  pinMode( pinDir8825,        OUTPUT );
  pinMode( pinStep8825,       OUTPUT );
  pinMode( PIN_ACTIVE_RELAIS, OUTPUT );
  pinMode( PinIntFinAVNC,     INPUT_PULLUP ); // détecteur de fin de rail
  pinMode( PinIntFinRCL,      INPUT_PULLUP ); // détecteur de fin de rail

  digitalWrite( PIN_ACTIVE_RELAIS, LOW);
 
  // *********** WIFI ****************************
  
  // ** Configuration d'une adresse IP statique **
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Impossible de configurer");
  }
  
  WiFi.begin(ssid, password);
  delay(1000);
  uint8_t retries = 15;
 
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print("..");
      Serial.print(WiFi.status());
      Serial.print("-");
      Serial.println(retries);
      retries--;
      if (retries == 0) {
        int intStatus = WiFi.status();
        if (intStatus==255){intStatus=2;}
        Serial.print("..");
        Serial.print(WiFi.status());
        Serial.print("-");
        Serial.println(retries);
        Serial.print("WiFi status :");
        Serial.print(WiFi.status());
        Serial.print("->");
        Serial.println(chStatusWifi[intStatus]); 
        stWifiConnectionNetwork = "Non connecté au réseau";
        break;
      }
  }

    Serial.println(stWifiConnectionNetwork);
  // ** Si Non connecté : Démarrage en mode POINT D'ACCÈS **
  if (stWifiConnectionNetwork=="Non connecté au réseau") {
     Serial.println("- * Activation du point d'accès Wifi * - ");
     WiFi.softAP(ssid_AP, password_AP);
     IPAddress myIP = WiFi.softAPIP();
     Serial.print("AP IP address: ");
     Serial.println(myIP);
  }
  else{
  Serial.print("WiFi status :");
  Serial.println(WiFi.status());
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  }
    
   server.begin();

    
  //**********  DEL *************
  // Configurer la minuterie et attacher la minuterie à la DEL
  ledcSetup(LEDC_CHANNEL_0_VERT, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(DELVERTE, LEDC_CHANNEL_0_VERT);
  ledcSetup(LEDC_CHANNEL_1_ROUGE, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(DELROUGE, LEDC_CHANNEL_1_ROUGE);

  AfficheVertCWRougePA();
  
  Serial.println("PRÊT");
}

// ------------------------------------------------------------------------------- 
// LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP 
// ------------------------------------------------------------------------------- 
void loop() {   
  do_Web();
  do_ExecCommande();
  compteur = 0;
}

  
           
