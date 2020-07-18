
//format bytes
String formatBytes(size_t bytes) {
  if (bytes < 1024) { return String(bytes) + "B";  }
  else if (bytes < (1024 * 1024)) {    return String(bytes / 1024.0) + "KB";  } 
  else if (bytes < (1024 * 1024 * 1024)) { return String(bytes / 1024.0 / 1024.0) + "MB"; }
  else { return String(bytes / 1024.0 / 1024.0 / 1024.0) + "GB";  }
}

String getContentType(String filename) {
  if (server.hasArg("download")) { return "application/octet-stream"; }
  else if (filename.endsWith(".htm"))   { return "text/html"; }
  else if (filename.endsWith(".html"))  { return "text/html"; }
  else if (filename.endsWith(".css"))   { return "text/css"; }
  else if (filename.endsWith(".js"))    { return "application/javascript"; }
  else if (filename.endsWith(".png")) { return "image/png";}
  else if (filename.endsWith(".gif")) { return "image/gif"; }
  else if (filename.endsWith(".jpg")) { return "image/jpeg";}
  else if (filename.endsWith(".ico")) {
    return "image/x-icon";
  } else if (filename.endsWith(".xml")) {
    return "text/xml";
  } else if (filename.endsWith(".pdf")) {
    return "application/x-pdf";
  } else if (filename.endsWith(".zip")) {
    return "application/x-zip";
  } else if (filename.endsWith(".gz")) {
    return "application/x-gzip";
  }
  return "text/plain";
}

bool exists(String path){
  bool yes = false;
  File file = SPIFFS.open(path, "r");
  if(!file.isDirectory()){    yes = true;  }
  file.close();
  return yes;
}

bool handleFileRead(String path) {
  //DBG_OUTPUT_PORT.println("handleFileRead: " + path);
  if (path.endsWith("/")) {    path += "index.htm";  }
  String contentType = getContentType(path);
  String pathWithGz = path + ".gz";
  if (exists(pathWithGz) || exists(path)) {
    if (exists(pathWithGz)) {      path += ".gz";    }
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, contentType);
    file.close();
    return true;
  }
  return false;
}

void handleFileUpload() {
  if (server.uri() != "/edit") { return; }
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    String filename = upload.filename;
    if (!filename.startsWith("/")) {      filename = "/" + filename;    }
    //DBG_OUTPUT_PORT.print("handleFileUpload Name: "); DBG_OUTPUT_PORT.println(filename);
    fsUploadFile = SPIFFS.open(filename, "w");
    filename = String();
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    if (fsUploadFile) { fsUploadFile.write(upload.buf, upload.currentSize); }
  } else if (upload.status == UPLOAD_FILE_END) {
    if (fsUploadFile) {      fsUploadFile.close();    }
    //DBG_OUTPUT_PORT.print("handleFileUpload Size: "); DBG_OUTPUT_PORT.println(upload.totalSize);
  }
}

void handleFileDelete() {
  if (server.args() == 0) {    return server.send(500, "text/plain", "BAD ARGS");  }
  String path = server.arg(0);
  //DBG_OUTPUT_PORT.println("handleFileDelete: " + path);
  if (path == "/") {    return server.send(500, "text/plain", "BAD PATH");  }
  if (!exists(path)) {    return server.send(404, "text/plain", "FileNotFound");  }
  SPIFFS.remove(path);
  server.send(200, "text/plain", "");
  path = String();
}

void handleFileList() {
  if (!server.hasArg("dir")) {
    server.send(500, "text/plain", "BAD ARGS");
    return;
  }
  String path = server.arg("dir");
  //DBG_OUTPUT_PORT.println("handleFileList: " + path);
  File root = SPIFFS.open(path);
  path = String();
  String output = "[";
  if(root.isDirectory()){
      File file = root.openNextFile();
      while(file){
          if (output != "[") {            output += ',';          }
          output += "{\"type\":\"";
          output += (file.isDirectory()) ? "dir" : "file";
          output += "\",\"name\":\"";
          output += String(file.name()).substring(1);
          output += "\"}";
          file = root.openNextFile();
      }
  }
  output += "]";
  server.send(200, "text/json", output);
}
