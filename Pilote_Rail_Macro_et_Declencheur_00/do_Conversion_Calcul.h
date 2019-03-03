// ------------------------------------------------------------------------------- 
//                 Conversion et calcul selon les paramètres reçus
// ------------------------------------------------------------------------------- 

void do_Conversion_calcul(){

      Serial.println(strDistParPas);  
      Serial.println(strDelaiAvantDeclenchement);
      Serial.println(strDelaiApresDeclenchement);
      Serial.println(strDistanceEntreCaptureVR);
      Serial.println(strNbreDePasEntreArrets);
      Serial.println(strNbreDeBoucle);
      Serial.println(strDistanceEntreCaptureVD);
      Serial.println(strDeplacementTotal);
      
                      
      if (strDistParPas !=""){
          fltDistParPas = strDistParPas.toFloat();
      }
      if (strDelaiAvantDeclenchement !=""){
         intDelaiAvantDeclenchement = strDelaiAvantDeclenchement.toInt();
      }              
      if (strDelaiApresDeclenchement !=""){
         intDelaiApresDeclenchement = strDelaiApresDeclenchement.toInt();
      }          
      if (strNbreDePasEntreArrets !=""){
         fltNbreDePasEntreArrets    = strNbreDePasEntreArrets.toFloat();
      }         
      if (strNbreDeBoucle !=""){
         intNbreDeBoucle = strNbreDeBoucle.toInt();
         fltDistanceEntreCapture    = fltNbreDePasEntreArrets * fltDistParPas;
         fltDeplacementTotal        = fltDistanceEntreCapture * intNbreDeBoucle;
      }                    
      if (strDistanceEntreCaptureVD !=""){
         fltDistanceEntreCapture    = strDistanceEntreCaptureVD.toFloat();
      }            
      if (strDeplacementTotal !=""){
         fltDeplacementTotal       = strDeplacementTotal.toFloat();
         fltNbreDePasEntreArrets   = fltDistanceEntreCapture / fltDistParPas;
         intNbreDePasEntreArrets   = fltNbreDePasEntreArrets;
         intNbreDeBoucle           = fltDeplacementTotal / fltDistanceEntreCapture;
      }          
     
      if (strDistanceEntreCaptureVR !=""){
         fltDistanceEntreCapture   = strDistanceEntreCaptureVR.toFloat();
         fltNbreDePasEntreArrets   = fltDistanceEntreCapture / fltDistParPas;
         intNbreDePasEntreArrets   = fltNbreDePasEntreArrets;
         fltDeplacementTotal       = intCompteurdePasRef * fltDistParPas;
         intNbreDeBoucle           = fltDeplacementTotal / fltDistanceEntreCapture;
      }          
      
  }
 
