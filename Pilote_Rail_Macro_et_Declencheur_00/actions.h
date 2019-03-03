//*************   Avancement - Chariot en fin de course ***************
void test_FinAVNC()                    
{
  if (digitalRead(PinIntFinAVNC) == HIGH) {
    digitalWrite(pinEnable8825, LOW);  // Active la sortie moteur
  } else {
    digitalWrite(pinEnable8825, HIGH); // Désactive la sortie moteur
    Serial.print( "RENDU EN FIN DE COURSE - " );
    intNbreDePasEntreArretsB = 0;
    intNbreDeBoucleB         = 0;
    intDelaiInterBoucleB     = 0; 
  }
}

//*************  Recul - Chariot en fin de course *********************
void test_FinRCL()                     
{
  if (digitalRead(PinIntFinRCL) == HIGH) {
    digitalWrite(pinEnable8825, LOW);   // Active la sortie moteur
  } else {
    digitalWrite(pinEnable8825, HIGH);  // Désactive la sortie moteur
    Serial.print( "RENDU EN FIN DE COURSE - " );
    intNbreDePasEntreArretsB = 0;
    intNbreDeBoucleB         = 0;
    intDelaiInterBoucleB     = 0;
  }
}


//*****************   Déclenche l'appareil photo   ********************
void declencheApp(){                  
  Serial.println( "CLICK " );
  digitalWrite( PIN_ACTIVE_RELAIS, HIGH);           
  delay(100);
  digitalWrite( PIN_ACTIVE_RELAIS, LOW);
  delay(intDelaiApresDeclenchement);  // Délai après déclenchement
  
  } 

//*****************   Exécute le déplacement vers l'avant   ********************
void execDeplacementAvance(){ 
  // intCompteurdePasRef -> sert pour accumuler le nombre de pas 
  // entre la référence A et la référence B
  // Si intCompteurdePasRef == 0 , on établi la direction
  // d'incrémentation du calcul de pas 
                     
  if ((intCompteurdePasRef == 0)&&( strDirectionRef==""))
    {
      strDirectionRef = "Avance";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinAVNC();
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirectionRef == "Avance")
        {
          intCompteurdePasRef++;
        }
        else
        {
          intCompteurdePasRef --;
        }
    }
    delay(intDelaiInterBoucleB); 
  }
}

//*****************   Exécute le déplacement vers l'arrière   ********************
void execDeplacementRecule(){ 
    if ((intCompteurdePasRef == 0)&&( strDirectionRef==""))
    {
      strDirectionRef = "Recule";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinRCL();
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirectionRef == "Recule")
        {
          intCompteurdePasRef++;
        }
        else 
        {
          intCompteurdePasRef --;
        }      
    } 
    delay(intDelaiInterBoucleB);      // attente
  }
}
  
//*****************   Avance très rapide   *****************************
void go_AvanceTresRapide()            
{
  digitalWrite( pinDir8825,    HIGH); // Direction avant
  digitalWrite( pinStep8825,   LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW ); // Active la sortie moteur
  intNbreDePasEntreArretsB   = 200;   // 200 * 0.02mm -> 4mm
  intNbreDeBoucleB           = 10;    // 10*4mm -> 40 mm -> 4cm
  intDelaiInterBoucleB       = 25; 
  execDeplacementAvance();
  Serial.println( "Avance très rapide terminée" );
}

//*****************   Avance rapide   *****************************
void go_AvanceRapide()               
{
  digitalWrite( pinDir8825,    HIGH); // Direction avant
  digitalWrite( pinStep8825,   LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW ); // Active la sortie moteur
  intNbreDePasEntreArretsB   = 200;   // 200 * 0.02mm -> 4mm
  intNbreDeBoucleB           = 3;     // 3*4mm -> 12 mm -> 1.2cm
  intDelaiInterBoucleB       = 25; 
  execDeplacementAvance();
  Serial.println( "Avance rapide terminée" );
}

//*****************   Avance lente   *****************************
void go_AvanceLente()                 // Avance lente
{
  digitalWrite( pinDir8825,    HIGH); // Direction avant
  digitalWrite( pinStep8825,   LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW ); // Active la sortie moteur
  intNbreDePasEntreArretsB   = 25;    // 25 * 0.02mm -> 0.5mm
  intNbreDeBoucleB           = 1;     
  intDelaiInterBoucleB       = 0;
  execDeplacementAvance();
  Serial.println( "Avance lente terminée" );
}

//******************   Arrêt du moteur  ********************************
void stop_Stop()  //Arrêt du moteur
{
  digitalWrite( pinEnable8825, HIGH ); // Désactive la sortie moteur
  Serial.println( "STOP" );
}

//*******************  Recule lente  ************************************
void go_ReculeLente()                  
{
  digitalWrite( pinDir8825,    LOW);   // Direction recule
  digitalWrite( pinStep8825,   LOW);   // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW );  // Active la sortie moteur
  intNbreDePasEntreArretsB   = 25;     // 25 * 0.02mm -> 0.5mm
  intNbreDeBoucleB           = 1;      
  intDelaiInterBoucleB       = 0;
  execDeplacementRecule();
  Serial.println( "Recule terminée" );
}

//*******************  Recule rapide  ***********************************
void go_ReculeRapide()                
{
  digitalWrite( pinDir8825,    LOW);  // Direction recule
  digitalWrite( pinStep8825,   LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW ); // Active la sortie moteur
  intNbreDePasEntreArretsB   = 200;   // 200 * 0.02mm -> 4mm
  intNbreDeBoucleB           = 3;     // 3*4mm -> 12 mm -> 1.2cm
  intDelaiInterBoucleB       = 25;
  execDeplacementRecule();
  Serial.println( "Recule rapide terminée" );
}

//*******************  Recule très rapide  *****************************
void go_ReculeTresRapide()        
{
  digitalWrite( pinDir8825,    LOW);  // Direction recule
  digitalWrite( pinStep8825,   LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable8825, LOW ); // Active la sortie moteur
  intNbreDePasEntreArretsB   = 200;   // 200 * 0.02mm -> 4mm
  intNbreDeBoucleB           = 10;    // 10*4mm -> 40 mm -> 4cm
  intDelaiInterBoucleB       = 25;    
  execDeplacementRecule();
  Serial.println( "Recule très rapide terminée" );
}

//-------------------- AVANCE CAPTURE ------------------------------- 
void go_AvanceCapture()                        // Avance et capture la photo
{
  digitalWrite( pinDir8825,  HIGH);            // Direction avant
  digitalWrite( pinStep8825, LOW);             // Initialisation de la broche step
  intPasAccompli = 0;
  for ( compteur = 0; compteur < intNbreDeBoucle; compteur++) {
    declencheApp();                            // Déclenche l'appareil photo 
    digitalWrite( pinEnable8825, LOW );        // Active la sortie moteur
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArrets; i++) {
      test_FinAVNC();                          // Vérifie si arrivé à la fin du rail
      if (digitalRead(PinIntFinAVNC) == LOW) {
        i = intNbreDePasEntreArrets;
        compteur  = intNbreDeBoucle;
      }
      intPasAccompli++;
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
    }
          if (intDesacMotPausBcl == 1)         // Désactive le moteur
        {
          digitalWrite( pinEnable8825, HIGH ); // Désactive la sortie moteur
        }
    //******** Attention : éviter serial.println ici, cela fait planter l'application android
    do_Web();                                  // Attention : ajoute un délai
    if (boExecStop) {
       boExecStop = false;
       compteur   = intNbreDeBoucle;
       stop_Stop();  
    }
    delay(intDelaiAvantDeclenchement);         // attente stabilité puis pose
   Serial.println( String(compteur+1) + "/" + String(intNbreDeBoucle)+ " " );   
  }
  declencheApp();                              // déclenche l'appareil photo 
  Serial.println( "Avance et capture terminée" );
  if (intRetourAuto == 1)                      // retour au point de départ
  {
    digitalWrite( pinDir8825,    LOW );        // inverse la direction
    digitalWrite( pinEnable8825, LOW );        // Active la sortie moteur
    for ( i = 0; i < intPasAccompli; i++) {
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
      test_FinRCL();   // ne devrait pas arriver sauf par une erreur de manipulation
      if (digitalRead(PinIntFinRCL) == LOW) {
        i = intPasAccompli;
      }
    }
  }
  if (intStopFinBoucle == 1)                   // STOP à la fin
  {
    digitalWrite( pinEnable8825, HIGH );       // Désactive la sortie moteur     
  }
}
//----------------- RECULE CAPTURE --------------------------------------- 
void go_ReculeCapture()                        // Recule et capture la photo
{
  digitalWrite( pinDir8825,      LOW );        // Direction recule
  digitalWrite( pinStep8825,     LOW ); 
  
  intPasAccompli=0;
  for ( compteur = 0; compteur < intNbreDeBoucle; compteur++) {
    declencheApp();                            // déclenche l'appareil photo 
    digitalWrite( pinEnable8825, LOW );        // Active la sortie moteur    
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArrets; i++) {
      test_FinRCL();                           // Vérifie si arrivé à la fin du rail
       if (digitalRead(PinIntFinRCL) == LOW) {
        i = intNbreDePasEntreArrets;
        compteur  = intNbreDeBoucle;
      }
      intPasAccompli++; // Accumule le nombre de pas accompli
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
    }
      if (intDesacMotPausBcl== 1)              // Désactive le moteur
        {
          digitalWrite( pinEnable8825, HIGH ); // Désactive le moteur     
        }
    //******** Attention: éviter serial.println ici, cela fait planter l'application android
    do_Web();                                 // Attention : ajoute un délai
    if (boExecStop) {
       boExecStop = false;
       compteur = intNbreDeBoucle;
       stop_Stop();  
    }
    Serial.println( String(compteur+1) + "/" + String(intNbreDeBoucle)+ " " );
    delay(intDelaiAvantDeclenchement);         // attente stabilité puis pose
  } // fin de for ( compteur = 0; compteur < intNbreDeBoucle; compteur++)
  
  declencheApp();                              // déclenche l'appareil photo 
  Serial.println( "Recule et capture terminée" );
  if (intRetourAuto == 1)                      // retour au point de départ
  {
    digitalWrite( pinDir8825   , HIGH);        // inverse la direction
    digitalWrite( pinEnable8825, LOW );        // Active le moteur
    for ( i = 0; i < intPasAccompli; i++) {
      digitalWrite( pinStep8825, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep8825, LOW );
      delayMicroseconds(timePulseStep);
      test_FinAVNC();
       if (digitalRead(PinIntFinAVNC) == LOW) {
        i = intPasAccompli;
      }
    }
  }
  if (intStopFinBoucle == 1)                    // STOP à la fin
  {
    digitalWrite( pinEnable8825, HIGH );        // Désactive le moteur   
  }
}

