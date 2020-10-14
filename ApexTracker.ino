/*
    Name:       button.ino
    Created:    2018/9/21 14:06:15
    Author:     sakabin
*/

#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


const char* ssid = "Buffalo-G-DFF0"; // SSID
const char* password = "45dutrdrdfh6a"; // PASSWORD

WiFiServer server(80);

// Wifiに接続
void setup()
{
    M5.begin(true, false, true);
    delay(100);
    M5.Lcd.setTextSize(3);  // 文字サイズ
    M5.Lcd.println("Connecting");

    // wifi接続開始
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        M5.Lcd.print(".");
    }

    // 接続完了したらIP表示
    M5.Lcd.println("Successed");
    M5.Lcd.println("IP: ");
    M5.Lcd.println(WiFi.localIP());
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(1);
    server.begin();

}

void loop(){
  // update button state

  M5.update();

  if (M5.BtnA.pressedFor(1000)){
    
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print("A button pressed");
    delay(1000);

  }else if(M5.BtnB.pressedFor(1000)){

       //jsonオブジェクトの作成
      DynamicJsonDocument doc(1024);

      M5.Lcd.println("Button B Clicked");
      HTTPClient http;

      http.begin("endpoint");
      
      int httpCode = http.GET();
      int response = http.getSize();
      M5.Lcd.println(String(response));
      if (httpCode > 0) {
          M5.Lcd.println("GET STRING");
          String response = http.getString();
          //以降、データに応じた処理
          deserializeJson(doc, response);
          JsonObject apexinfo = doc.as<JsonObject>();
          
          String rank = apexinfo["rank"];
          String value = apexinfo["value"];
          String rankName = apexinfo["metadata"]["rankName"];

          M5.Lcd.clear(BLACK);
          M5.Lcd.setCursor(0, 0);
          M5.Lcd.setTextSize(4);
          M5.Lcd.setTextColor(YELLOW);
          M5.Lcd.println("APEX TRACKER");
          M5.Lcd.setTextColor(WHITE);
          M5.Lcd.println("------------");
          M5.Lcd.setTextSize(3);
          M5.Lcd.println("Name : Username");
          M5.Lcd.println("");
          M5.Lcd.println("rank :" + String(rank));
          M5.Lcd.println("");
          M5.Lcd.println("PR :" + String(value));
          M5.Lcd.println("");
          M5.Lcd.println("Tier :" + String(rankName));

      } else {
          M5.Lcd.println("Error on HTTP request");
      }
      http.end();
     delay(1000);
  }else if(M5.BtnC.pressedFor(1000)){
    M5.Lcd.clear(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print("C button pressed");
    delay(1000);
  }

}
