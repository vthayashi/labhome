
#include <Update.h>

void update_setup(){
    server.on("/update", HTTP_GET, []() {
      server.sendHeader("Connection", "close");
      String pg;
      pg=F(
        "<style>\n"
        " .custom-file-input{border:solid 1px silver;border-radius:4px;}"
        " .custom-file-input::-webkit-file-upload-button {visibility:hidden;width:0;border-radius:4px;}\n"
        "</style>\n"
        "<div align=center><table>\n"
        "<tr><td align='center'><b>Update (Firmware)</b></td></tr>\n"
        "<form method='POST' action='/update' enctype='multipart/form-data'>"
        "<tr><td><input class='custom-file-input' type='file' name='update'>\n"
        "</td></tr>\n"
        "<tr><td align='center'><input type='submit' value='Update'></form></td></tr>"
        "</table></div>"
      );
      server.send(200, "text/html", pg);
    });
    server.on("/update", HTTP_POST, []() {
      server.sendHeader("Connection", "close");
      String pg;
      pg=F(
        "<html>"
        "<meta http-equiv='refresh' content='10; url=/'>"
        "<script>"
        "var cnt=15;"
        "function iniciar(){setInterval(timer,500);};"
        "function timer(){cnt--;span01.innerHTML+='.';if(cnt<=0){location.href='/';}};"
        "</script>"
        "<body onload='iniciar();'>"
        "<span id='span01'>Reiniciando</span>"
        "</body>"
        "</html>"
      );
      server.send(200, "text/html", (Update.hasError()) ? "FAIL" : pg);
      server.handleClient();delay(100);
      ESP.restart();
    },[]() {
      HTTPUpload& upload = server.upload();
      if (upload.status == UPLOAD_FILE_START) {
        if (!Update.begin()) {} //start with max available size
      } else if (upload.status == UPLOAD_FILE_WRITE) {
        if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {}
      } else if (upload.status == UPLOAD_FILE_END) {
        if (Update.end(true)) {} //true to set the size to the current progress
      }
    } );
}
