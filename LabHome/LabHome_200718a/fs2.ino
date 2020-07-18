void handleFormat(){
  String pg;
  pg = F("<html><body onload='history.go(-1);'></body></html>");
  server.send(200, "text/html", pg);
  SPIFFS.format();
}

void handleUpload() {
  String pg;
  pg = F(
         "<html>\n"
         "<head>\n"
         "<meta name='viewport' content='width=device-width, initial-scale=1'>\n"
         "<style>\n"
         " body{margin:4px 0 0 0;}\n"
         " input{border:solid 1px silver;border-radius:4px;background-color:white;cursor:hand;}"
         //" .custom-file-input{border:solid 1px silver;border-radius:4px;}\n"
         " .custom-file-input::-webkit-file-upload-button {visibility:hidden;width:0;}\n"
         "</style>\n"
         "<script>\n"
         " function loadList(){xh.open(\"GET\", \"/list?dir=/\", true); xh.send(null);};\n"
         " function iniciar(){setTimeout(loadList(),500);}\n"
         "var xh = new XMLHttpRequest();\n"
         "xh.onreadystatechange = function(){\n"
         "  if (xh.readyState == 4){\n"
         "    if(xh.status == 200) {\n"
         "    var res = JSON.parse(xh.responseText);\n"
         "    aa=[];for(i in res){aa[aa.length]=res[i].name;}\n"
         "    aa.sort(); div01.innerHTML='';\n"
         "    for(i in aa){\n"
         "      div01.innerHTML+='<input type=button value=del onclick=del(\"'+aa[i]+'\"); >';\n"
         "      div01.innerHTML+=\" <a href='\"+aa[i]+\"'>\"+aa[i]+\"</a><br>\";\n"
         "    }\n"
         "   }\n"
         "  }\n"
         " };\n"
         "var xh2 = new XMLHttpRequest();\n"
         "xh2.onreadystatechange = function(){\n"
         "  if (xh2.readyState == 4){\n"
         "      if(xh2.status == 200) {setTimeout(loadList(),100);}\n"
         "  }\n"
         "};\n"
         "function del(path){\n"
         "  if(confirm('Excluir '+path+'?\')==true){\n"
         "    xh2.open('DELETE', '/edit?path=/'+path, true); xh2.send(null);\n"
         "  }\n"
         "}\n"
         "\n"
         "function updateChange(){\n"
         " sb=update.value;\n"
         " if(sb.length<1){submitBtn.disabled=true;}else{submitBtn.disabled=false;}\n"
         "}\n"
         "</script>\n"
         "</head>\n"
         "\n"
         "<body>\n"
         "<div align='center'>\n"
         "<div style='width:352px;margin:2px;border:solid 1px silver;border-radius:4px;'>\n"
         "<table border='0' cellspacing='0' cellpadding='2'><tr>\n"
         "<form target='if01' action='/edit' method='post' enctype='multipart/form-data'>\n"
         "<td><input type='button' value='<' style='width:28px;height:23px;' onclick='history.go(-1);'></td>\n"
         "<td><input id='update' type='file' name='name' class='custom-file-input' onchange='updateChange()'></td>\n"
         "<td><input id='submitBtn' type='submit' value='Upload' disabled style='height:23px;'></td>\n"
         "</form>\n"
         "</tr></table></div>\n"
         
         "<div style='width:352px;margin:2px;border:solid 1px silver;border-radius:4px;'>\n"
         "<table><tr><td id='div01'>\n"
         "</td></tr></table></div>\n"

         "<div style='width:352px;margin:2px;border:solid 1px silver;border-radius:4px;'>\n"
         "usedBytes: "); pg+=SPIFFS.usedBytes(); pg+=F(" - totalBytes: "); pg+=SPIFFS.totalBytes(); pg+=F("\n"
         "</div>\n"
         
         "<iframe id='if01' name='if01' onload='iniciar();' style='visibility:hidden;'></iframe>\n"
         "</div></body></html>"
       );
  server.send(200, "text/html", pg);
}
