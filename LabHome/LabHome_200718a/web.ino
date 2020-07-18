void web_setup(){
  //SERVER INIT
  String sa;
  server.on("/", handleRoot);
  sa=F("/upload");  server.on(sa.c_str(), handleUpload);
  sa=F("/format");  server.on(sa.c_str(), handleFormat);
  server.on("/list", HTTP_GET, handleFileList);
  server.on("/edit", HTTP_GET, []() { if (!handleFileRead("/edit.htm")){server.send(404, "text/plain", "FileNotFound");}});
  server.on("/edit", HTTP_DELETE, handleFileDelete);
  server.on("/edit", HTTP_POST, []() { server.send(200, "text/plain", ""); }, handleFileUpload);
  server.onNotFound([]() { if (!handleFileRead(server.uri())) { server.send(404, "text/plain", "FileNotFound"); } });
  //
  sa=F("/js"); server.on(sa.c_str(), handleJson);
  server.begin();
}

void handleRoot() {
  String sa; sa=F("/index.htm");
  if (exists(sa)) if(handleFileRead(sa)) return;
  String pg="";
  pg+=F(
    "<html><head>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "</head>"
    "<body>\n"
    "<div align=center>"
    "<b>"); pg+=Versao; pg+=F("</b>\n"
    "<hr width='320'>\n"
    "<a href='/upload'>Arquivos</a> -\n"
    "<a href='/edit'>edit</a> -\n"
    "<a href='/update'>Update (Firmware)</a>\n"
    "<br><hr width='320'>\n"
    "</div></body></html>"
  );
  server.send(200, "text/html", pg);
}
