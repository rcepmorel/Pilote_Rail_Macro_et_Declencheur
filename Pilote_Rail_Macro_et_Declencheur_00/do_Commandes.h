// ------------------------------------------------------------------------------- 
//                 Exécution des commandes reçues
// ------------------------------------------------------------------------------- 

void do_Commandes(){
          
         if (currentLine.startsWith("GET /action_page.php?")){
         // Trouver le début de la donnée de chaque variable et lire cette donnée
         int posResolutionDuRail = currentLine.indexOf("ResolutionDuRail=");
         int posDelaiAvantDeclenchement = currentLine.indexOf("DelaiAvantDeclenchement=");
         int posDelaiApresDeclenchement = currentLine.indexOf("DelaiApresDeclenchement=");
         int posDistanceEntreCaptureVR = currentLine.indexOf("DistanceEntreCaptureVR=");
         int posNbreDePasEntreArrets = currentLine.indexOf("NbreDePasEntreArrets=");
         int posNbreDeBoucle = currentLine.indexOf("NbreDeBoucle=");
         int posDistanceEntreCaptureVD = currentLine.indexOf("DistanceEntreCaptureVD=");
         int posDeplacementTotal = currentLine.indexOf("DeplacementTotal=");
         int posHTTP = currentLine.indexOf("HTTP");
           if (posResolutionDuRail >0) { 
             Serial.println("");
             Serial.println("***" );
             Serial.print(posResolutionDuRail);
             Serial.println(" position de ResolutionDuRail" );
             Serial.print(posDelaiAvantDeclenchement);
             Serial.println(" position de DelaiAvantDeclenchement" );
             Serial.print(posDelaiApresDeclenchement);
             Serial.println(" position de DelaiApresDeclenchement" );
             Serial.print(posDistanceEntreCaptureVR);
             Serial.println(" position de DistanceEntreCaptureVR" );
             Serial.print(posNbreDePasEntreArrets);
             Serial.println(" position de NbreDePasEntreArrets" );
             Serial.print(posNbreDeBoucle);
             Serial.println(" position de NbreDeBoucle" );
             Serial.print(posDistanceEntreCaptureVD);
             Serial.println(" position de DistanceEntreCaptureVD" );
             Serial.print(posDeplacementTotal);
             Serial.println(" position de DeplacementTotal" );
             //Serial.println(currentLine);

             strDistParPas = currentLine.substring(posResolutionDuRail+17,posDelaiAvantDeclenchement-1);
             strDelaiAvantDeclenchement = currentLine.substring(posDelaiAvantDeclenchement+24,posDelaiApresDeclenchement-1);
             strDelaiApresDeclenchement = currentLine.substring(posDelaiApresDeclenchement+24,posDistanceEntreCaptureVR-1);
             strDistanceEntreCaptureVR = currentLine.substring(posDistanceEntreCaptureVR+23,posNbreDePasEntreArrets-1);
             strNbreDePasEntreArrets = currentLine.substring(posNbreDePasEntreArrets+21,posNbreDeBoucle-1);
             strNbreDeBoucle = currentLine.substring(posNbreDeBoucle+13,posDistanceEntreCaptureVD-1);
             strDistanceEntreCaptureVD = currentLine.substring(posDistanceEntreCaptureVD+23,posDeplacementTotal-1);
             strDeplacementTotal = currentLine.substring(posDeplacementTotal+17,posHTTP-1);
                
             do_Conversion_calcul();
             bolSetParametreRepere = false;
           }                // fin du if (posResolutionDuRail >0) { 
        }                   // fin du if (currentLine.startsWith("GET /action_page.php?")){
           
        if (currentLine.endsWith("GET /PhotoClic HTTP/1.1")) {
           boExecDeclencheApp = true; 
        }
        
        if (currentLine.endsWith("GET /AvanceLente HTTP/1.1")) {
           boExecAvanceLente = true;  
        }    
        if (currentLine.endsWith("GET /AvanceRapide HTTP/1.1")) {
           boExecAvanceRapide = true; 
        } 
        if (currentLine.endsWith("GET /AvanceTresRapide HTTP/1.1")) {
           boExecAvanceTresRapide = true; 
        }       
        if (currentLine.endsWith("GET /STOP HTTP/1.1")) {
           boExecStop = true;;  
        }
        if (currentLine.endsWith("GET /ReculeLente HTTP/1.1")) {
           boExecReculeLente = true;  
        }    
        if (currentLine.endsWith("GET /ReculeRapide HTTP/1.1")) {
           boExecReculeRapide = true;
        } 
        if (currentLine.endsWith("GET /ReculeTresRapide HTTP/1.1")) {
           boExecReculeTresRapide = true;  
        } 
        if (currentLine.endsWith("GET /RepereA HTTP/1.1")) {
           boExecRepereA = true;    
        } 
        if (currentLine.endsWith("GET /RepereB HTTP/1.1")) {
           boExecRepereB = true; 
           bolSetParametreRepere = true;
        } 
        if (currentLine.endsWith("GET /ACapture HTTP/1.1")) {
           boExecAvanceCapture = true;    
        }
        if (currentLine.endsWith("GET /RCapture HTTP/1.1")) {
           boExecReculeCapture = true;   
        }

}

