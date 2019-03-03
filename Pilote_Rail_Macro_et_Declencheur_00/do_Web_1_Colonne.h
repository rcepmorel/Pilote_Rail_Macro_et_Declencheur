// ------------------------------------------------------------------------------- 
//   serveur WEB    serveur WEB     serveur WEB      serveur WEB      serveur WEB 
// ------------------------------------------------------------------------------- 

void do_Web(){
   WiFiClient client = server.available(); // Écouter les clients entrants

  if (client) {                            // si vous avez un client,
    Serial.println("Nouveau Client!");     // imprimer un message sur le port série
    int inChronoDebutConnexion= millis();   

    while (client.connected()) {           // boucle alors que le client est connecté

      if ((millis() - inChronoDebutConnexion) > 1000){ // Déconnecte les fureteurs qui restent
          client.stop();                                // connecter sans avoir d'échange à
          inChronoDebutConnexion= millis();             // faire comme Chrome                           
       }   
       
      if (client.available()) {           // s'il y a des octets à lire du client,
         char c = client.read();          // lire un octet, puis
         //Serial.write(c);               // Imprimez sur le moniteur série
         if (c == '\n') {                 // si l'octet est un caractère
                                          // de nouvelle ligne

           // si la ligne en cours est vide, vous avez
           // deux caractères de nouvelle ligne consécutifs.
           // c'est la fin de la requête HTTP du client,
           // alors envoyez une réponse:
           if (currentLine.length() == 0) {
             client.println("HTTP/1.1 200 OK");
             client.println("Content-Type: text/html\n");


client.println("<!DOCTYPE html>");
client.println("<html>");
client.println("<head>");
client.println("<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">");
client.println("<title>CTRL - Rail Macrophotographie</title>");
client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");

client.println("<style type=\"text/css\">");      
client.println("html {");
client.println("font-family: Helvetica;");
client.println("display: inline-block;");
client.println("max-width: 500px;");
client.println("margin: auto;");
client.println("text-align: center;");
client.println("}");
client.println("h1{");
client.println("color: #0F3376;");
client.println("padding: 2vh;");
client.println("}");
client.println("h2{");
client.println("color: #0F3376;");
client.println("font-size: 1.0em;");
client.println("margin-top: 0.67em;");
client.println("margin-bottom: 0.67em;");
client.println("margin-left: 0;");
client.println("margin-right: 0;");
client.println("font-weight: bold;");
client.println("font-style: italic;");
client.println("}");
client.println("h3{");
client.println("color: #ff0000;");
client.println("font-size: 1.0em;");
client.println("margin-top: 0.67em;");
client.println("margin-bottom: 0.67em;");
client.println("margin-left: 0;");
client.println("margin-right: 0;");
client.println("font-weight: bold;");
client.println("font-style: italic;");
client.println("}");
client.println("p{");
client.println("font-size: 1.5rem;");
client.println("}");
client.println(".button {");
client.println("display: inline-block;");
client.println("background-color: #008CBA;");
client.println("border: none;");
client.println("border-radius: 4px;");
client.println("color: white;");
client.println("padding: 16px 40px;");
client.println("text-decoration: none;");
client.println("font-size: 30px;");
client.println("margin: 2px;");
client.println("cursor: pointer;");
client.println("}");
client.println(".button2 {");
client.println("background-color: #555555;");
client.println("}");
client.println("table.Type_A{");
client.println("width: 1000px;");
client.println("padding: 30px;");
client.println("border: 0px solid red;"); 
client.println("background-color: #ffffff;");  
client.println("}");

client.println("table.Type_B{");
client.println("width: 450px;");
client.println("height: 200px;");
client.println("border: 1px solid black;"); 
client.println("background-color: #888888;");  
client.println("}");

client.println("table.Type_C{");
client.println("width: 450px;");
client.println("height: 130px;");
client.println("border: 1px solid black;"); 
client.println("background-color: #888888;");  
client.println("}");

client.println("table.Type_D{");
client.println("width: 450px;");
client.println("border: 1px solid black;"); 
client.println("background-color: #888888;");  
client.println("}");

client.println("</style>");

client.println("</head>");
client.println("<body>");
client.println("<h2>- Contrôleur - Rail Macrophotographie -</h2>");
if (bolSetParametreRepere){
client.println("<h3>- Configurez PARAMETRES VERSUS REPÈRES -</h3>");
}

//-----------------------  CONTRÔLE DE L'ACTION   -----------------------------------------------------------//


//****DÉPLACEMENT ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>DÉPLACEMENT</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td>AVANCE</td>");
client.println("<td>STOP</td>");
client.println("<td>RECULE</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/AvanceLente\"><button class=\"button\">&lt;</button></a></td>");
client.println("<td><a href=\"/STOP\"><button class=\"button\">||</button></a></td>");
client.println("<td><a href=\"/ReculeLente\"><button class=\"button\">&gt;</button></a></td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/AvanceRapide\"><button class=\"button\">&lt;&lt;</button></a></td>");
client.println("<td><a href=\"/STOP\"><button class=\"button\">||</button></a></td>");
client.println("<td><a href=\"/ReculeRapide\"><button class=\"button\">&gt;&gt;</button></a></td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/AvanceTresRapide\"><button class=\"button\">&lt;&lt;&lt;</button></a></td>");
client.println("<td><a href=\"/STOP\"><button class=\"button\">||</button></a></td>");
client.println("<td><a href=\"/ReculeTresRapide\"><button class=\"button\">&gt;&gt;&gt;</button></a></td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");
client.println("<table class=\"Type_C\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>Suivi de capture</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"width: 450px;\" ><h2>");
client.println(String(compteur) + "/" + String(intNbreDeBoucle));
client.println("</h2></td>");
client.println("<td><a href=\"/Actualiser\"><button class=\"button button2\">Actualiser</button></a></td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");

//****FIXE LES REPÈRES ****
client.println("<table class=\"Type_C\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>FIXE LES REPÈRES</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/RepereA\"><button class=\"button\">A</button></a></td>");
client.println("<td><a href=\"/RepereB\"><button class=\"button\">B</button></a></td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");



//****CAPTURE ****
client.println("<table class=\"Type_D\">");

client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/ACapture\"><button class=\"button button2\">&lt;Capture</button></a></td>");
client.println("<td><a href=\"/RCapture\"><button class=\"button button2\">Capture&gt;</button></a></td>");
client.println("</tr>");

client.println("</table>");


//****PHOTOCLIC ****
client.println("<table class=\"Type_D\">");

client.println("<tr bgcolor=\"#888888\">");
client.println("<td><a href=\"/PhotoClic\"><button class=\"button button2\">PhotoClic</button></a></td>");
client.println("</tr>");

client.println("</table>");



//-----------------------  AFFICHAGE -----------------------------------------------------------//
client.println("<br><br>");
client.println("<hr>");
client.println("<br><br>");



//****PARAMÈTRES GÉNÉRAUX ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" style=\"height: 20px;\" bgcolor=\"#aaaaaa\"><h2>PARAMÈTRES GÉNÉRAUX</h2></td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px; width: 250px;\" ><b>Résolution du rail</b></td>");
client.println("<td style=\"width: 100px;\">"+String(fltDistParPas)+"</td>");
client.println("<td style=\"text-align: left;\">&nbsp;<i>mm</i></td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\" ><b>Délai avant déclenchement</b><br>");
client.println("</td>");
client.println("<td>"+String(intDelaiAvantDeclenchement)+"<br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px;\">&nbsp;<i>milliseconde</i><br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px; width: 250px;\" ><b>&nbsp;Délai après déclenchement</b></td>");
client.println("<td>"+String(intDelaiApresDeclenchement)+"</td>");
client.println("<td style=\"text-align: left;\">&nbsp;<i>milliseconde</i>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");

//****PARAMÈTRES VERSUS REPÈRES ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS REPÈRES</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Distance entre les captures</b><br>");
client.println("</td>");
client.println("<td style=\"width: 100px;\">"+String(fltDistanceEntreCapture)+"<br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px;\" >&nbsp;<i>mm</i><br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");


//****PARAMÈTRES VERSUS PAS ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS PAS</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\" ><b>Nombre de pas entre les arrêts</b><br>");
client.println("</td>");
client.println("<td style=\"width: 100px;\">"+String(fltNbreDePasEntreArrets)+"<br>");
client.println("</td>");
client.println("<td style=\"width: 110px;\">-<br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\" ><b>Nombre de boucle</b><br>");
client.println("</td>");
client.println("<td>"+String(intNbreDeBoucle)+"<br>");
client.println("</td>");
client.println("<td>-<br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");

//****PARAMÈTRES VERSUS DISTANCE ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS DISTANCE</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Distance entre les captures</b><br>");
client.println("</td>");
client.println("<td style=\"width: 100px;\">"+String(fltDistanceEntreCapture)+"<br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px;\" >&nbsp;<i>mm</i><br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Déplacement total</b><br>");
client.println("</td>");
client.println("<td>"+String(fltDeplacementTotal)+"<br>");
client.println("</td>");
client.println("<td style=\"text-align: left;\">&nbsp;<i>mm</i><br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");


//--------------------  ENTRÉE DES DONNÉES  -------------------------------------------------//
client.println("<br><br>");
client.println("<hr>");
client.println("<br><br>");
client.println("<form action=\"/action_page.php\">");



//****PARAMÈTRES GÉNÉRAUX ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" style=\"height: 20px;\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES GÉNÉRAUX</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; width: 250px;\"><b>Résolution du rail</b><br>");
client.println("</td>");
client.println("<td style=\"width: 100px;\"><input name=\"ResolutionDuRail\" type=\"number\" step=\"0.01\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px; padding: 10px;\">mm<br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Délai avant déclenchement</b><br>");
client.println("</td>");
client.println("<td><input name=\"DelaiAvantDeclenchement\" type=\"number\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left; padding: 10px;\">milliseconde<br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; width: 250px;\"><b>&nbsp; Délai après déclenchement</b><br>");
client.println("</td>");
client.println("<td style=\"width: 100px;\"><input name=\"DelaiApresDeclenchement\" type=\"number\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left; padding: 10px;\">milliseconde<br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");

//****PARAMÈTRES VERSUS REPÈRES ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS REPÈRES</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Distance entre les captures</b><br>");
client.println("</td>");
client.println("<td><input name=\"DistanceEntreCaptureVR\" type=\"number\" step=\"0.01\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px;\" >&nbsp;mm<br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");


client.println("<br>");
client.println("<input value=\"Soumettre\" type=\"submit\"><br>");
client.println("<br>");



//****PARAMÈTRES VERSUS PAS ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS PAS</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Nombre de pas entre les arrêts</b><br>");
client.println("</td>");
client.println("<td><input name=\"NbreDePasEntreArrets\" type=\"number\"><br>");
client.println("</td>");
client.println("<td style=\"width: 110px;\">-<br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Nombre de boucle</b><br>");
client.println("</td>");
client.println("<td><input name=\"NbreDeBoucle\" type=\"number\"><br>");
client.println("</td>");
client.println("<td>-<br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");

//****PARAMÈTRES VERSUS DISTANCE ****
client.println("<table class=\"Type_B\">");

client.println("<tr>");
client.println("<td colspan=\"3\" bgcolor=\"#aaaaaa\">");
client.println("<h2>PARAMÈTRES VERSUS DISTANCE</h2>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Distance entre les captures</b><br>");
client.println("</td>");
client.println("<td><input name=\"DistanceEntreCaptureVD\" type=\"number\" step=\"0.01\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left; width: 110px;\">&nbsp;mm<br>");
client.println("</td>");
client.println("</tr>");
client.println("<tr bgcolor=\"#888888\">");
client.println("<td style=\"text-align: right; padding: 10px;\"><b>Déplacement total</b><br>");
client.println("</td>");
client.println("<td><input name=\"DeplacementTotal\" type=\"number\" step=\"0.01\"><br>");
client.println("</td>");
client.println("<td style=\"text-align: left;\">&nbsp;mm<br>");
client.println("</td>");
client.println("</tr>");

client.println("</table>");

client.println("<br>");
client.println("<input value=\"Soumettre\" type=\"submit\"><br>");
client.println("<br>");

client.println("</form>");

client.println("</body>");
client.println("</html>");

             break;  // break out of the while loop
           }         // fin du if (currentLine.length() == 0) 
           else {    // currentLine.length() != 0 et c == '\n' (nouvelle ligne)
            // Une ligne de commandes est reçue
            do_Commandes();
            currentLine = "";  // si vous avez un caractère de nouvelle ligne, effacez currentLine:
           }                   // fin du else { // currentLine.length() != 0
         }                     // fin du if (c == '\n')  
  
         else if (c != '\r') 
         {  // si vous avez autre chose qu'un caractère de retour de chariot,
          currentLine += c;    // l'ajouter à la fin de la currentLine
         // Serial.println(currentLine);
         }
       }                       // # if (client.available())
     }                         // # fin du while (client.connected())
     client.stop();            // close the connection:
     Serial.println("Client Déconnecté");
  } // # fin du if (client) 
}
 
