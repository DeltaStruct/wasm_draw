#include <emscripten.h>
#include <iostream>
#include <vector>
using namespace std;

EM_JS(void, jsFunction, (const char* message), {
  var jsMessage = UTF8ToString(message);
  window.alert(jsMessage);
});
class draw_canvas {
  // canvasを使用する
  publiwc:
  int height,width;

  /* Call JavaScript function*/
  void fillRect(int x,int y,int w,int h){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.fillRect($0,$1,$2,$3);
    },x,y,w,h);
  }
  void strokeRect(int x,int y,int w,int h){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.strokeRect($0,$1,$2,$3);
    },x,y,w,h);
  }
  void clearRect(int x,int y,int w,int h){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.clearRect($0,$1,$2,$3);
    },x,y,w,h);
  }
  void fillText(const char* text,int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      console.log(typeof($0));
      ctx.fillText(UTF8ToString($0),$1,$2);
    },text,x,y);
  }
  void strokeText(const char* text,int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.strokeText(UTF8ToString($0),$1,$2);
    },text,x,y);
  }
  void beginPath(){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.beginPath();
    });
  }
  void closePath(){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.closePath();
    });
  }
  void moveTo(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.moveTo($0,$1);
    },x,y);
  }
  void lineTo(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.lineTo($0,$1);
    },x,y);
  }
  void stroke(){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.stroke();
    });
  }
  void fill(){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.fill();
    });
  }
  void arc(int x,int y,int r,int s,int e){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.arc($0,$1,$2,$3,$4);
    },x,y,r,s,e);
  }
  void arcTo(int x1,int y1,int x2,int y2,int r){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.arcTo($0,$1,$2,$3,$4);
    },x1,y1,x2,y2,r);
  }
  void quadraticCurveTo(int cpx,int cpy,int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.quadraticCurveTo($0,$1,$2,$3);
    },cpx,cpy,x,y);
  }
  void bezierCurveTo(int cp1x,int cp1y,int cp2x,int cp2y,int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext
      ctx.bezierCurveTo($0,$1,$2,$3,$4,$5);
    },cp1x,cp1y,cp2x,cp2y,x,y);
  }
  void rect(int x,int y,int w,int h){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.rect($0,$1,$2,$3);
    },x,y,w,h);
  }
  void clip(){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.clip();
    });
  }
  void isPointInPath(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.isPointInPath($0,$1);
    },x,y);
  }
  void isPointInStroke(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.isPointInStroke($0,$1);
    },x,y);
  }
  void rotate(int angle){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.rotate($0);
    },angle);
  }
  void scale(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.scale($0,$1);
    },x,y);
  }
  void translate(int x,int y){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.translate($0,$1);
    },x,y);
  }
  void setFillColor(int r,int g,int b,double a){
    EM_ASM({
      var canvas = document.getElementById('canvas');
      var ctx = canvas.getContext('2d');
      ctx.fillStyle = "rgba("+String($0)+","+String($1)+","+String($2)+","+String($3)+")";
      console.log(ctx.fillStyle);
    },r,g,b,a);
  }

  /* Constructor */
  draw_canvas(){
    height = EM_ASM_INT({ return window.innerHeight; });
    width = EM_ASM_INT({ return window.innerWidth; });
    EM_ASM({
      var canvas = document.createElement('canvas');
      canvas.id = 'canvas';
      canvas.height = window.innerHeight;
      canvas.width = window.innerWidth;
      document.body.prepend(canvas);
    });
    this->setFillColor(54,69,79,1);
    this->fillRect(0,0,this->width,this->height);
    const char* a = "a";
    jsFunction(a);
    this->setFillColor(255,69,79,1);
    this->fillText("made by DeltaStruct",0,0);
  }
} draw;

int main(){
  return 0;
}