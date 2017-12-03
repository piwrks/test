
void bargraph_verlauf()
{
  
  analogWrite(backlight_pin, backlight_on);
    
  int x, y;
  int res = 0;
     
 waitForTouchRelease();    
  
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(255, 255, 255);
  
  myGLCD.drawLine(0, 19, 799, 19);
  myGLCD.drawLine(400, 0, 400, 479);
  //myGLCD.drawLine(0, 240, 799, 240);
  
  myGLCD.setFont(BVS_15);
  
  myGLCD.print("Innen - Klima 24h", 140, 0, 0);
  myGLCD.print("Aussen - Klima 24h", 540, 0, 0);
  
  myGLCD.setFont(BVS_15);
  

  //Skalen Zeichnen
  
   
  
  //Skala Temp Innen 
  
   myGLCD.drawLine(55, 28, 55, 230);
  
  myGLCD.drawLine(45, 230, 65, 230); //1
   myGLCD.print("10", 10, 225, 0);
   
   myGLCD.drawLine(45, 191, 65, 191); //2
   myGLCD.print("15", 10, 186, 0);
   
   myGLCD.drawLine(45, 150, 65, 150); //3
   myGLCD.print("20", 10, 145, 0);
   
   myGLCD.drawLine(45, 109, 65, 109); //4
   myGLCD.print("25", 10, 104, 0);
   
   myGLCD.drawLine(45, 68.75, 65, 68.75); //5
   myGLCD.print("30", 10, 63.75, 0);
    
    myGLCD.drawLine(45, 27, 65, 27); //6
    myGLCD.print("35", 10, 22, 0);
     
     
       //Skala Hum Innen
  
   myGLCD.drawLine(55, 268, 55, 470);
  
   myGLCD.drawLine(45, 470, 65, 470); //1
   myGLCD.print("20", 10, 465, 0);
   
   myGLCD.drawLine(45, 437.5, 65, 437.5); //2
   myGLCD.print("30", 10, 432.5, 0);
   
   myGLCD.drawLine(45, 403.5, 65, 403.5); //3
   myGLCD.print("40", 10, 398.5, 0);
   
   myGLCD.drawLine(45, 369, 65, 369); //4
   myGLCD.print("50", 10, 364, 0);
   
   myGLCD.drawLine(45, 335, 65, 335); //5
   myGLCD.print("60", 10, 330, 0);
   
   myGLCD.drawLine(45, 301, 65, 301); //6
   myGLCD.print("70", 10, 296, 0);
     
   myGLCD.drawLine(45, 267, 65, 267); //7
   myGLCD.print("80", 10, 262, 0);
     
   //Skala Temp Aussen 
  
   myGLCD.drawLine(454, 28, 454, 230);
    
   myGLCD.drawLine(444, 230, 464, 230); //1
   myGLCD.print("-15", 408, 225, 0);
   
   myGLCD.drawLine(444, 203.9, 464, 203.9); //2
   myGLCD.print("-7.5", 405, 198.9, 0); 
   
   myGLCD.drawLine(444, 176.5, 464, 176.5); //3
   myGLCD.print("0", 419, 171.5, 0);
     
   myGLCD.drawLine(444, 138.4, 464, 138.4); //4
   myGLCD.print("10", 412, 133.4, 0);  
     
   myGLCD.drawLine(444, 101, 464, 101); //5
   myGLCD.print("20", 412, 96, 0); 
  
   myGLCD.drawLine(444, 64, 464, 64); //6
   myGLCD.print("30", 412, 59, 0); 
     
   myGLCD.drawLine(444, 27, 464, 27); //7
   myGLCD.print("40", 412, 22, 0); 
   
   //Skala Hum Aussen
   
   myGLCD.drawLine(454, 268, 454, 470);
  
    myGLCD.drawLine(444, 470, 464, 470); //1
   myGLCD.print("20", 412, 465, 0);
   
   myGLCD.drawLine(444, 420, 464, 420); //2
   myGLCD.print("40", 412, 415, 0);
      
   myGLCD.drawLine(444, 369, 464, 369); //3
   myGLCD.print("60", 412, 363, 0);
       
   myGLCD.drawLine(444, 318, 464, 318); //4
   myGLCD.print("80", 412, 312, 0);
     
   myGLCD.drawLine(444, 267, 464, 267); //5
   myGLCD.print("100", 407, 263, 0);
   
    
  
   //Graphen zeichen
  
  drawGraphTempInnen(historyTempInnen, 24);
  drawGraphHumInnen(historyHumInnen, 24);
  
  drawGraphTempAussen(historyTempAussen, 24);
  drawGraphHumAussen(historyHumAussen, 24);
     
   
  // Zurück zum Hauptbildschirm
    
  while (res==0)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
       if ((y>=0) && (y<=480)) // Touchbereich um zurückzukehren
      {
        if ((x>=0) && (x<=800))
        {
          res=2;
          myGLCD.setColor (255, 0, 0);
          myGLCD.drawRoundRect(1, 1, 799, 479);
        }
      }
    }
  }
  
  waitForTouchRelease();
  
myGLCD.clrScr();

 initGraphics();
 
  renderDatum();
  renderTempInnen();
  renderTempAussen();
  renderBarometer();
  rendertaupunkt();
  renderhumidex();
  renderaktuell();
  renderforecast();
  rendermoon();
  rendermoondays();
  rendersonne();
  renderheizung(); 
  drawMillibarGraph(historyBaro, 24);
 
}

//******************* BARGRAPHEN ************************

//Temp Innen

void drawBarTempInnen(int index, int value, int valueOffset){
  
  int maxValue = 100*2.05; //100; height factor
  
  // lower left corner coordinates for the bargrah
  int yaxis = 230; //Höhe
  int xaxis = 80; //Links/Rechts
  
  int margin = 2;
  int width = 12; //6;
  
  int height = (value - valueOffset)*8.175; //Set height with * factor
    if (height < 1){
  height = 0;
  }
  int x1 = index * width;
  int x2 = x1 + width - margin;
 

  // draw it
  myGLCD.setColor(10,50,10);
  myGLCD.fillRect(xaxis + x1, yaxis, xaxis + x2, yaxis-height);
  
  // top very visible
  myGLCD.setColor(50,220,50);
  int markerHeight = 5;
  if (height < markerHeight){
    markerHeight = height;
  }
  myGLCD.fillRect(xaxis + x1, yaxis-height, xaxis + x2, yaxis-height+markerHeight);
  
  // clear top (to replace previous bar if it was higher)
   myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(xaxis + x1, yaxis - maxValue, xaxis + x2, yaxis-height);

}

void drawGraphTempInnen(int values[], int nr_of_values){
  
  for (int i = 0; i< nr_of_values; i++){
    drawBarTempInnen(i,values[i], 10); // value offset 5 gives us 0 in graph for 10°C
  }
}

//Temp Aussen

void drawBarTempAussen(int index, int value, int valueOffset){
  
  int maxValue = 100*2.05; //100; height factor
  
  // lower left corner coordinates for the bargrah
  int yaxis = 230; //Höhe
  int xaxis = 490; //Links/Rechts
  
  int margin = 2;
  int width = 12; //6;
  
 
  int height = (value - valueOffset)*3.725; //Set height with * factor
  //  if (height < 1){
 // height = 0;
 // }
  int x1 = index * width;
  int x2 = x1 + width - margin;
 

  // draw it
  myGLCD.setColor(10,50,10);
  myGLCD.fillRect(xaxis + x1, yaxis, xaxis + x2, yaxis-height);
  
  // top very visible
  myGLCD.setColor(50,220,50);
  int markerHeight = 5;
  if (height < markerHeight){
    markerHeight = height;
  }
  myGLCD.fillRect(xaxis + x1, yaxis-height, xaxis + x2, yaxis-height+markerHeight);
  
  // clear top (to replace previous bar if it was higher)
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(xaxis + x1, yaxis - maxValue, xaxis + x2, yaxis-height);

}

void drawGraphTempAussen(int values[], int nr_of_values){
  
  for (int i = 0; i< nr_of_values; i++){
    drawBarTempAussen(i,values[i], -15); // value offset -15 gives us 0 in graph for -15°C
  }
}

//Hum Innen

void drawBarHumInnen(int index, int value, int valueOffset){
  
  int maxValue = 100*2.05; //100; height factor
  
  // lower left corner coordinates for the bargrah
  int yaxis = 470; //Höhe
  int xaxis = 80; //Links/Rechts
  
  int margin = 2;
  int width = 12; //6;
  
  int height = (value - valueOffset)*3.4; //Set height with * factor
    if (height < 1){
  height = 0;
  }
  int x1 = index * width;
  int x2 = x1 + width - margin;
 

  // draw it
  myGLCD.setColor(10,50,10);
  myGLCD.fillRect(xaxis + x1, yaxis, xaxis + x2, yaxis-height);
  
  // top very visible
  myGLCD.setColor(50,220,50);
  int markerHeight = 5;
  if (height < markerHeight){
    markerHeight = height;
  }
  myGLCD.fillRect(xaxis + x1, yaxis-height, xaxis + x2, yaxis-height+markerHeight);
  
  // clear top (to replace previous bar if it was higher)
    myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(xaxis + x1, yaxis - maxValue, xaxis + x2, yaxis-height);

}

void drawGraphHumInnen(int values[], int nr_of_values){
  
  for (int i = 0; i< nr_of_values; i++){
    drawBarHumInnen(i,values[i], 20); // value offset 20 gives us 0 in graph for 20´%
  }
}

//Hum Aussen

void drawBarHumAussen(int index, int value, int valueOffset){
  
  int maxValue = 100*2.05; //100; height factor
  
  // lower left corner coordinates for the bargrah
  int yaxis = 470; //Höhe
  int xaxis = 490; //Links/Rechts
  
  int margin = 2;
  int width = 12; //6;
  
  int height = (value - valueOffset)*2.56; //Set height with * factor
    if (height < 1){
  height = 0;
  }
  int x1 = index * width;
  int x2 = x1 + width - margin;
 

  // draw it
  myGLCD.setColor(10,50,10);
  myGLCD.fillRect(xaxis + x1, yaxis, xaxis + x2, yaxis-height);
  
  // top very visible
  myGLCD.setColor(50,220,50);
  int markerHeight = 5;
  if (height < markerHeight){
    markerHeight = height;
  }
  myGLCD.fillRect(xaxis + x1, yaxis-height, xaxis + x2, yaxis-height+markerHeight);
  
  // clear top (to replace previous bar if it was higher)
    myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(xaxis + x1, yaxis - maxValue, xaxis + x2, yaxis-height);

}

void drawGraphHumAussen(int values[], int nr_of_values){
  
  for (int i = 0; i< nr_of_values; i++){
    drawBarHumAussen(i,values[i], 20); // value offset 20 gives us 0 in graph for 20´%
  }
}
