// ------------------------------------------------------------------------------- 
//                 Exécution des commandes reçues
// ------------------------------------------------------------------------------- 

void do_Commandes(){
          
         if (currentLine.startsWith("GET /action_page.php?")){
         // Trouver la position du début de la donnée de chaque variable et lire cette donnée
         int intPosResolutionDuRail = currentLine.indexOf("ResolutionDuRail=");
         int intPosDelaiAvantDeclenchement = currentLine.indexOf("DelaiAvantDeclenchement=");
         int intPosDelaiApresDeclenchement = currentLine.indexOf("DelaiApresDeclenchement=");
         int intPosDistanceEntreCaptureVR = currentLine.indexOf("DistanceEntreCaptureVR=");
         int intPosNbreDePasEntreArrets = currentLine.indexOf("NbreDePasEntreArrets=");
         int intPosNbreDeBoucle = currentLine.indexOf("NbreDeBoucle=");
         int intPosDistanceEntreCaptureVD = currentLine.indexOf("DistanceEntreCaptureVD=");
         int intPosDeplacementTotal = currentLine.indexOf("DeplacementTotal=");
         int intPosHTTP = currentLine.indexOf("HTTP");
           if (intPosResolutionDuRail >0) { 
             Serial.println("");
             Serial.println("***" );
             Serial.print(intPosResolutionDuRail);
             Serial.println(" position de ResolutionDuRail" );
             Serial.print(intPosDelaiAvantDeclenchement);
             Serial.println(" position de DelaiAvantDeclenchement" );
             Serial.print(intPosDelaiApresDeclenchement);
             Serial.println(" position de DelaiApresDeclenchement" );
             Serial.print(intPosDistanceEntreCaptureVR);
             Serial.println(" position de DistanceEntreCaptureVR" );
             Serial.print(intPosNbreDePasEntreArrets);
             Serial.println(" position de NbreDePasEntreArrets" );
             Serial.print(intPosNbreDeBoucle);
             Serial.println(" position de NbreDeBoucle" );
             Serial.print(intPosDistanceEntreCaptureVD);
             Serial.println(" position de DistanceEntreCaptureVD" );
             Serial.print(intPosDeplacementTotal);
             Serial.println(" position de DeplacementTotal" );
             //Serial.println(currentLine);

             strDistParPas = currentLine.substring(intPosResolutionDuRail+17,intPosDelaiAvantDeclenchement-1);
             strDelaiAvantDeclenchement = currentLine.substring(intPosDelaiAvantDeclenchement+24,intPosDelaiApresDeclenchement-1);
             strDelaiApresDeclenchement = currentLine.substring(intPosDelaiApresDeclenchement+24,intPosDistanceEntreCaptureVR-1);
             strDistanceEntreCaptureVR = currentLine.substring(intPosDistanceEntreCaptureVR+23,intPosNbreDePasEntreArrets-1);
             strNbreDePasEntreArrets = currentLine.substring(intPosNbreDePasEntreArrets+21,intPosNbreDeBoucle-1);
             strNbreDeBoucle = currentLine.substring(intPosNbreDeBoucle+13,intPosDistanceEntreCaptureVD-1);
             strDistanceEntreCaptureVD = currentLine.substring(intPosDistanceEntreCaptureVD+23,intPosDeplacementTotal-1);
             strDeplacementTotal = currentLine.substring(intPosDeplacementTotal+17,intPosHTTP-1);
                
             do_Conversion_calcul();
             bolSetParametreRepere = false;
           }                // fin du if (intPosResolutionDuRail >0) { 
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

