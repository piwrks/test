void barkurve_verlauf()
{
  
  analogWrite(backlight_pin, backlight_on);
    
  int x, y;
  int res = 0;
     
 waitForTouchRelease();    
  
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  
  myGLCD.setColor(255, 255, 255);
  
  myGLCD.drawLine(0, 19, 799, 19);
  
  myGLCD.setFont(BVS_15);
  
  myGLCD.print("Barometer hPA", 340, 0, 0);
  
  myGLCD.setFont(BVS_15);
 
 
 //Skala Zeichnen
 
  myGLCD.drawLine(60, 35, 60, 420);
  myGLCD.drawLine(60, 420, 780, 420); //950

  myGLCD.setColor( 77,77,77); 
  
  myGLCD.drawLine(61, 385, 780, 385); //960
  myGLCD.drawLine(61, 350, 780, 350); //970
  myGLCD.drawLine(61, 315, 780, 315); //980
  myGLCD.drawLine(61, 280, 780, 280); //990
  myGLCD.drawLine(61, 245, 780, 245); //1000
  myGLCD.drawLine(61, 210, 780, 210); //1010
  myGLCD.drawLine(61, 175, 780, 175); //1020
  myGLCD.drawLine(61, 140, 780, 140); //1030
  myGLCD.drawLine(61, 105, 780, 105); //1040
  myGLCD.drawLine(61, 70, 780, 70); //1050
  myGLCD.drawLine(61, 35, 780, 35); //1060
  
  
  myGLCD.drawLine(90, 35, 90, 420); //1 Stunde
  myGLCD.drawLine(120, 35, 120, 420); //2 Stunden
  myGLCD.drawLine(150, 35, 150, 420); //3 Stunden
  myGLCD.drawLine(180, 35, 180, 420); //3 Stunden
  myGLCD.drawLine(210, 35, 210, 420); //3 Stunden
 myGLCD.drawLine(240, 35, 240, 420); //3 Stunden
 myGLCD.drawLine(270, 35, 270, 420); //3 Stunden
 myGLCD.drawLine(300, 35, 300, 420); //3 Stunden
 myGLCD.drawLine(330, 35, 330, 420); //3 Stunden
 myGLCD.drawLine(360, 35, 360, 420); //3 Stunden
 myGLCD.drawLine(390, 35, 390, 420); //3 Stunden
 myGLCD.drawLine(420, 35, 420, 420); //3 Stunden
 myGLCD.drawLine(450, 35, 450, 420); //3 Stunden
 myGLCD.drawLine(480, 35, 480, 420); //3 Stunden
 myGLCD.drawLine(510, 35, 510, 420); //3 Stunden
 myGLCD.drawLine(540, 35, 540, 420); //3 Stunden
 myGLCD.drawLine(570, 35, 570, 420); //3 Stunden
 myGLCD.drawLine(600, 35, 600, 420); //3 Stunden
 myGLCD.drawLine(630, 35, 630, 420); //3 Stunden
 myGLCD.drawLine(660, 35, 660, 420); //3 Stunden
 myGLCD.drawLine(690, 35, 690, 420); //3 Stunden
 myGLCD.drawLine(720, 35, 720, 420); //3 Stunden
 myGLCD.drawLine(750, 35, 750, 420); //3 Stunden
 myGLCD.drawLine(780, 35, 780, 420); //3 Stunden
 
 // Beschriftung Skala
 
  
   //Graphen zeichen
  
  drawkurve();
      
   
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

//******************* Barometer Kurve ************************

//Barometer Kurve


void drawkurve()
{
  
int bar1p0y1=420; int bar1p1y1=420; int bar1p2y1=420; int bar1p3y1=420; int bar1p4y1=420; int bar1p5y1=420; int bar1p6y1=420; int bar1p7y1=420;
int bar1p8y1=420; int bar1p9y1=420; int bar1p10y1=420; int bar1p11y1=420; int bar1p12y1=420; int bar1p13y1=420; int bar1p14y1=420; int bar1p15y1=420;
int bar1p16y1=420; int bar1p17y1=420; int bar1p18y1=420; int bar1p19y1=420; int bar1p20y1=420; int bar1p21y1=420; int bar1p22y1=420; int bar1p23y1=420;

//Serial.println(historyBarokurve[0]); 

//187+((t1p4)*-9);

bar1p0y1=420+((historyBarokurve[0]-950)*-3.5);
bar1p1y1=420+((historyBarokurve[1]-950)*-3.5);
bar1p2y1=420+((historyBarokurve[2]-950)*-3.5);
bar1p3y1=420+((historyBarokurve[3]-950)*-3.5);
bar1p4y1=420+((historyBarokurve[4]-950)*-3.5);
bar1p5y1=420+((historyBarokurve[5]-950)*-3.5);
bar1p6y1=420+((historyBarokurve[6]-950)*-3.5);
bar1p7y1=420+((historyBarokurve[7]-950)*-3.5);
bar1p8y1=420+((historyBarokurve[8]-950)*-3.5);
bar1p9y1=420+((historyBarokurve[9]-950)*-3.5);
bar1p10y1=420+((historyBarokurve[10]-950)*-3.5);
bar1p11y1=420+((historyBarokurve[11]-950)*-3.5);
bar1p12y1=420+((historyBarokurve[12]-950)*-3.5);
bar1p13y1=420+((historyBarokurve[13]-950)*-3.5);
bar1p14y1=420+((historyBarokurve[14]-950)*-3.5);
bar1p15y1=420+((historyBarokurve[15]-950)*-3.5);
bar1p16y1=420+((historyBarokurve[16]-950)*-3.5);
bar1p17y1=420+((historyBarokurve[17]-950)*-3.5);
bar1p18y1=420+((historyBarokurve[18]-950)*-3.5);
bar1p19y1=420+((historyBarokurve[19]-950)*-3.5);
bar1p20y1=420+((historyBarokurve[20]-950)*-3.5); 
bar1p21y1=420+((historyBarokurve[21]-950)*-3.5);
bar1p22y1=420+((historyBarokurve[22]-950)*-3.5);
bar1p23y1=420+((historyBarokurve[23]-950)*-3.5);

  
myGLCD.setColor(135,206,250);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 0.00 Uhr
myGLCD.drawLine(60,bar1p0y1,90,bar1p1y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 1.00 Uhr
myGLCD.drawLine(90,bar1p1y1,120,bar1p2y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 2.00 Uhr
myGLCD.drawLine(120,bar1p2y1,150,bar1p3y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 3.00 Uhr
myGLCD.drawLine(150,bar1p3y1,180,bar1p4y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 4.00 Uhr
myGLCD.drawLine(180,bar1p4y1,210,bar1p5y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 5.00 Uhr
myGLCD.drawLine(210,bar1p5y1,240,bar1p6y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 6.00 Uhr
myGLCD.drawLine(240,bar1p6y1,270,bar1p7y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 7.00 Uhr
myGLCD.drawLine(270,bar1p7y1,300,bar1p8y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 8.00 Uhr
myGLCD.drawLine(300,bar1p8y1,330,bar1p9y1);
//------------------------------------------------------------------------------------------------------------ -Draw Line at 9.00 Uhr
myGLCD.drawLine(330,bar1p9y1,360,bar1p10y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 10.00 Uhr
myGLCD.drawLine(360,bar1p10y1,390,bar1p11y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 11.00 Uhr
myGLCD.drawLine(390,bar1p11y1,420,bar1p12y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 12.00 Uhr
myGLCD.drawLine(420,bar1p12y1,450,bar1p13y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 13.00 Uhr
myGLCD.drawLine(450,bar1p13y1,480,bar1p14y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 14.00 Uhr
myGLCD.drawLine(480,bar1p14y1,510,bar1p15y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 15.00 Uhr
myGLCD.drawLine(510,bar1p15y1,540,bar1p16y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 16.00 Uhr
myGLCD.drawLine(540,bar1p16y1,570,bar1p17y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 17.00 Uhr
myGLCD.drawLine(570,bar1p17y1,600,bar1p18y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 18.00 Uhr
myGLCD.drawLine(600,bar1p18y1,630,bar1p19y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 19.00 Uhr
myGLCD.drawLine(630,bar1p19y1,660,bar1p20y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 20.00 Uhr
myGLCD.drawLine(660,bar1p20y1,690,bar1p21y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 21.00 Uhr
myGLCD.drawLine(690,bar1p21y1,720,bar1p22y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 22.00 Uhr
myGLCD.drawLine(720,bar1p22y1,750,bar1p23y1);
//----------------------------------------------------------------------------------------------------------- -Draw Line at 23.00 Uhr
myGLCD.drawLine(750,bar1p23y1,780,bar1p0y1);
}
//------------------------------------}
  
  





