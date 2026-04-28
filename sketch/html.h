#ifndef HTML_CONTENT_H
#define HTML_CONTENT_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<!doctype html>
<html>

<head>
    
    <meta name='viewport' content='width=device-width,initial-scale=1'>
    <style>
        
    body{font-family:sans-serif; font-size: 20px; padding:20px; margin: 0;}
    form{margin-bottom:20px;}
    input,textarea,button{width: calc(100%-20px); font-size: 20px;}
    .entry{border-bottom:1px solid #ff0404;padding:8px 0}
        
    </style>
    
</head>


<body>
    <form action='/send-message' method='post'>
        <input name='name' placeholder='name'><br><br>
        <textarea name='msg' placeholder='message'></textarea><br><br>
        <button>Submit</button>
        </form>
    <hr>
)rawliteral";

#endif