
void test_FinAVNC()  //Chariot en fin de course
{
  if (digitalRead(PinIntFinAVNC) == HIGH) {
    digitalWrite(pinEnable, LOW);
  } else {
    digitalWrite(pinEnable, HIGH); // désactive la sortie moteur
    Serial.print( "RENDU EN FIN DE COURSE - " );
    intNbreDePasEntreArretsB = 0;
    intNbreDeBoucleB = 0;
    intDelaiInterBoucleB = 0; 
  }
}

void test_FinRCL()  //Chariot en fin de course
{
  if (digitalRead(PinIntFinRCL) == HIGH) {
    digitalWrite(pinEnable, LOW);
  } else {
    digitalWrite(pinEnable, HIGH); // désactive la sortie moteur
    Serial.print( "RENDU EN FIN DE COURSE - " );
    intNbreDePasEntreArretsB = 0;
    intNbreDeBoucleB = 0;
    intDelaiInterBoucleB = 0;
  }
}


void declencheApp(){
  Serial.println( "CLICK " );
  digitalWrite( PIN_ACTIVE_RELAIS, HIGH);           
  delay(100);
  digitalWrite( PIN_ACTIVE_RELAIS, LOW);
  delay(intDelaiApresDeclenchement);        // Délai après déclenchement
  
  } 


void go_AvanceTresRapide()        // Avance très rapide
{
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // Active le circuit (logique inversée)
  intNbreDePasEntreArretsB = 200; // 100 pour 1 mm
  intNbreDeBoucleB = 10;          // 10*200/100mm = 20 mm = 2cm
  intDelaiInterBoucleB = 25;
  if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Avance";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinAVNC();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Avance")
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
  Serial.println( "Avance très rapide terminé" );
}

void go_AvanceRapide()            // Avance rapide
{
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // logique inversée
  intNbreDePasEntreArretsB = 200; // 100 pour 1 mm
  intNbreDeBoucleB = 3;           // 10*200/100mm = 20 mm = 2cm
  intDelaiInterBoucleB = 25;
    if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Avance";
    }
  for ( int cpt = 0; cpt < intNbreDeBoucleB; cpt++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinAVNC();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Avance")
        {
          intCompteurdePasRef++;
        }
        else
        {
          intCompteurdePasRef --;
        }
    }
    delay(intDelaiInterBoucleB); // attente
  }
  Serial.println( "Avance rapide termine" );
}

//***********************************************************************
void go_AvanceLente()             // Avance lente
{
  digitalWrite( pinDir   , HIGH); // Direction avant
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // logique inversée
  intNbreDePasEntreArretsB = 25;  // 100 pour 1 mm
  intNbreDeBoucleB = 1;           // 1*1 mm = 1 mm = 0,1cm
  intDelaiInterBoucleB = 0;
    if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Avance";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinAVNC();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Avance")
        {
          intCompteurdePasRef++;
        }
        else 
        {
          intCompteurdePasRef --;
        }
   
   }
    delay(intDelaiInterBoucleB); // attente
  }
  Serial.println( "Avance lente terminé" );

}

//***********************************************************************
void stop_Stop()  //Arrêt du moteur
{
  digitalWrite( pinEnable, HIGH ); // logique inversée
  Serial.println( "STOP" );
}

//***********************************************************************
void go_ReculeLente()             // Recule lente
{
  digitalWrite( pinDir   , LOW);  // Direction recule
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // logique inversée
  intNbreDePasEntreArretsB = 25;  // 100 pour 1 mm
  intNbreDeBoucleB = 1;           // 1*1 mm = 1 mm = 0,1cm
  intDelaiInterBoucleB = 0;
    if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Recule";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinRCL();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Recule")
        {
          intCompteurdePasRef++;
        }
        else 
        {
          intCompteurdePasRef --;
        }
      
    } 
    delay(intDelaiInterBoucleB); // attente
  }
  Serial.println( "Recule terminé" );
}

void go_ReculeRapide()            //Recule rapide
{
  digitalWrite( pinDir   , LOW);  // Direction recule
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // logique inversée
  intNbreDePasEntreArretsB = 200; // 100 pour 1 mm
  intNbreDeBoucleB = 3;           // 10*200/100mm = 20 mm = 2cm
  intDelaiInterBoucleB = 25;
      if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Recule";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinRCL();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Recule")
        {
          intCompteurdePasRef++;
        }
        else
        {
          intCompteurdePasRef --;
        }  
    }
    delay(intDelaiInterBoucleB); // attente
  }
  Serial.println( "Recule rapide termine" );
}

void go_ReculeTresRapide()        // Recule très rapide
{
  digitalWrite( pinDir   , LOW);  // Direction recule
  digitalWrite( pinStep  , LOW);  // Initialisation de la broche step
  digitalWrite( pinEnable, LOW ); // logique inversée
  intNbreDePasEntreArretsB = 200; // 100 pour 1 mm
  intNbreDeBoucleB = 10;          // 10*200/100mm = 20 mm = 2cm
  intDelaiInterBoucleB = 25;
      if ((intCompteurdePasRef == 0)&&( strDirection==""))
    {
      strDirection = "Recule";
    }
  for ( compteur = 0; compteur < intNbreDeBoucleB; compteur++) {
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArretsB; i++) {
      test_FinRCL();
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      if (strDirection == "Recule")
        {
          intCompteurdePasRef++;
        }
        else
        {
          intCompteurdePasRef --;
        }  
    }
    delay(intDelaiInterBoucleB); // attente
  }
  Serial.println( "Recule très rapide terminé" );
}

//----------------- AVANCE CAPTURE ---------------- 
void go_AvanceCapture()                   // Avance et capture la photo
{
  digitalWrite( pinDir   , HIGH);         // Direction avant
  digitalWrite( pinStep  , LOW);          // Initialisation de la broche step
  intPasAccompli =0;
  for ( compteur = 0; compteur < intNbreDeBoucle; compteur++) {
    declencheApp();                       // déclenche l'appareil photo 
    digitalWrite( pinEnable, LOW );       // logique inversée
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArrets; i++) {
      test_FinAVNC();
      if (digitalRead(PinIntFinAVNC) == LOW) {
        i = intNbreDePasEntreArrets;
        compteur  = intNbreDeBoucle;
      }
      intPasAccompli++;
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
    }
          if (intDesacMotPausBcl== 1)       // Désactive le moteur
        {
          digitalWrite( pinEnable, HIGH );
        }
    //******** Attention :éviter serial.println ici, cela fait planter l'application android
    do_Web(); // Attention : ajoute un délai
    if (boExecStop) {
       boExecStop = false;
       compteur = intNbreDeBoucle;
       stop_Stop();  
    }
    delay(intDelaiAvantDeclenchement);                   // attente stabilité puis pose
   Serial.println( String(compteur+1) + "/" + String(intNbreDeBoucle)+ " " );
   
  }
  declencheApp();                            // déclenche l'appareil photo 
  Serial.println( "Avance et capture terminé" );
  if (intRetourAuto == 1)                    // retour au point de départ
  {
    digitalWrite( pinDir   , LOW);           // inverse la direction
    digitalWrite( pinEnable, LOW );
    for ( i = 0; i < intPasAccompli; i++) {
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      test_FinRCL();   // ne devrait pas arriver sauf par une erreur de manipulation
      if (digitalRead(PinIntFinRCL) == LOW) {
        i = intPasAccompli;
      }
    }
  }
  if (intStopFinBoucle == 1)                   // STOP à la fin
  {
    digitalWrite( pinEnable, HIGH );            
  }
}
//----------------- RECULE CAPTURE ---------------- 
void go_ReculeCapture()                        // Recule et capture la photo
{
  digitalWrite( pinDir   , LOW); // Direction avant
  digitalWrite( pinStep  , LOW); 
  
  intPasAccompli=0;
  for ( compteur = 0; compteur < intNbreDeBoucle; compteur++) {
    declencheApp();                             // déclenche l'appareil photo 
    digitalWrite( pinEnable, LOW );            
    // Avance de X pas
    for ( i = 0; i < intNbreDePasEntreArrets; i++) {
      test_FinRCL();     // Vérifie si arrivé à la fin du rail
       if (digitalRead(PinIntFinRCL) == LOW) {
        i = intNbreDePasEntreArrets;
        compteur  = intNbreDeBoucle;
      }
      intPasAccompli++; // Accumule le nombre de pas accompli
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
    }
      if (intDesacMotPausBcl== 1)              // Désactive le moteur
        {
          digitalWrite( pinEnable, HIGH );      
        }
    //******** Attention: éviter serial.println ici, cela fait planter l'application android
    do_Web(); // Attention : ajoute un délai
    if (boExecStop) {
       boExecStop = false;
       compteur = intNbreDeBoucle;
       stop_Stop();  
    }
    Serial.println( String(compteur+1) + "/" + String(intNbreDeBoucle)+ " " );
    delay(intDelaiAvantDeclenchement);          // attente stabilité puis pose
  } // fin de for ( compteur = 0; compteur < intNbreDeBoucle; compteur++)
  
  declencheApp();                               // déclenche l'appareil photo 
  Serial.println( "Recule et capture terminé" );
  if (intRetourAuto == 1)                       // retour au point de départ
  {
    digitalWrite( pinDir   , HIGH);             // inverse la direction
    digitalWrite( pinEnable, LOW );
    for ( i = 0; i < intPasAccompli; i++) {
      digitalWrite( pinStep, HIGH );
      delayMicroseconds(timePulseStep);
      digitalWrite( pinStep, LOW );
      delayMicroseconds(timePulseStep);
      test_FinAVNC();
       if (digitalRead(PinIntFinAVNC) == LOW) {
        i = intPasAccompli;
      }
    }
  }
  if (intStopFinBoucle == 1)                     // STOP à la fin
  {
    digitalWrite( pinEnable, HIGH );            
  }
}

