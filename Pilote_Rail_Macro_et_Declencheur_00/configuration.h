//******* Affichage DEL ********
// Afin d'ajuster au besoin l'intensité et la couleur de la DEL, le programme
// fait appel une fonction (ledcWrite) qui module la sortie PWM des broches
// selon la valeur fournie à la fonction
#define LEDC_CHANNEL_0_VERT     0
#define LEDC_CHANNEL_1_ROUGE    1

// use 13 bit precission for LEDC timer
#define LEDC_TIMER_13_BIT  13

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ     5000

#define DELROUGE  12 // DEL rouge reliée au GPIO12
#define DELVERTE  13 // DEL verte reliée au GPIO13

byte byBrightnessVert;
byte byBrightnessRouge;


#define PIN_ACTIVE_RELAIS           32   // Déclenche l'appareil photo+flashs

#define pinDir8825                  14   // Direction
#define pinStep8825                 27   // Signal de PAS (avancement) PWM
#define pinEnable8825               25   // Activation du driver/pilote
#define PinIntFinRCL                26   // Détecteur de fin de rail
#define PinIntFinAVNC               33   // Détecteur de fin de rail

// **** DRV8825 et Nema 17 17HD48002H-22B V sur le potentiomètre ajusté à 0,585V ***
// microseconde (minimum 600 pour Nema 17, plus rapide, moins bruyant)
// microseconde (minimum 900 pour le rail DBX1204-100, plus rapide, moins bruyant)
int timePulseStep                 = 900; 
int i                             = 0;   // Compteur pour la boucle NbreDePasEntreArret
int compteur                      = 0;   // Compteur pour la boucle NbreDeBoucle
int intPasAccompli                = 0;

int intDelaiAvantDeclenchement    = 1000;  // milliseconde ( 1 secondes d'arrêt puis déclenche )

int intNbreDePasEntreArrets       = 500;   // 100 pour 1 mm pour le nema 17 , le DBX1204-100 2 mm
int intNbreDeBoucle               = 4;
int intDelaiApresDeclenchement    = 1000;

int intNbreDePasEntreArretsB      = 0;
int intNbreDeBoucleB              = 0;
int intDelaiInterBoucleB          = 0;

float fltDistParPas               = 0.020; // mm, 10 um pour 1 pas Nema 17 plus vis
float fltDistanceEntreCapture     = 0;     // distance fonction du nombre de pas, dimension d'une tranche
float fltDeplacementTotal         = 0;     // distance totale parcourue selon le nombre de pas et de boucle
float fltNbreDePasEntreArrets     = 0;     // Nombre de pas par boucle

String strDistParPas              = "0.02";
String strNbreDePasEntreArrets    = "-";
String strNbreDeBoucle            = "-";
String strDelaiApresDeclenchement = "-";
String strDelaiAvantDeclenchement = "-";
String strDeplacementTotal        = "-";

String strDistanceEntreCaptureVD  = "-";

String strDistanceEntreCaptureVR  = "-";

int intRetourAuto                 = 1;
int intStopFinBoucle              = 1;
int intDesacMotPausBcl            = 1;

int intCompteurdePasRef           = 0;
String strDirectionRef            = "";

String currentLine                = "";    // Variable de type String pour contenir
                                           // les données entrantes du client
bool bolSetParametreRepere        = false;
bool boExecDeclencheApp           = false;
bool boExecAvanceLente            = false;
bool boExecAvanceRapide           = false;
bool boExecAvanceTresRapide       = false; 
bool boExecStop                   = false;
bool boExecReculeLente            = false;
bool boExecReculeRapide           = false;
bool boExecReculeTresRapide       = false;
bool boExecRepereA                = false;
bool boExecRepereB                = false;
bool boExecAvanceCapture          = false;
bool boExecReculeCapture          = false;



