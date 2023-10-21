#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
// WiFi network
const char* ssid     = "Infinix HOT 9 Play";
const char* password = "1998@19981";
ESP8266WebServer server ( 80 );
char htmlResponse[3000];
void handleRoot() {
 snprintf ( htmlResponse, 3000,
"<!DOCTYPE html>\
<html lang=\"en\">\
 <head>\
 <style>\
body {background-color: rgb(160, 0, 53);}\
h3   {color: white;text-align:center;}\
p    {color: white; text-align:center;}\
div  {color: white; text-align:center;}\
ID {text-align:center;}\
input {text-align:center;}\
</style>\
   <meta charset=\"utf-8\">\
   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
 </head>\
 <body>\
         <h3>\<canter>Electropeak Smart Security Door</canter>\</h3>\
         <p>\<canter>Please type your ID</canter>\</p>\
         <div>ID: <input type='text' name='pass_word' id='pass_word' align='center' size=10 autofocus></div> \
         <div>\
         <br><button id=\"save_button\">Log In</button>\
         </div>\
   <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js\"></script>\    
   <script>\
     var pass;\
     $('#save_button').click(function(e){\
       e.preventDefault();\
       pass = $('#pass_word').val();\        
       $.get('/save?pass=' + pass, function(data){\
         console.log(data);\
       });\
     });\      
   </script>\
 </body>\
</html>"); 
  server.send ( 200, "text/html", htmlResponse );  
}
void handleSave() {
 if (server.arg("pass")!= ""){
   Serial.println(server.arg("pass"));
 }
}
void setup() {
 // Start serial
 Serial.begin(115200);
 delay(10);
 // Connecting to a WiFi network
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");  
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 server.on ( "/", handleRoot );
 server.on ("/save", handleSave);
 server.begin();
 Serial.println ( "HTTP server started" );
}
void loop() {
 server.handleClient();
} 
