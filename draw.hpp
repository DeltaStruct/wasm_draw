#include <emscripten.h>
#include <vector>
using namespace std;

EM_JS(int,get_window_height,(),{
  return window.innerHeight;
});
EM_JS(int,get_window_width,(),{
  return window.innerWidth;
});

class draw_canvas {
  // canvasを使用する
  int height,width;
  public:
  draw_canvas(){
    height = get_window_height();
    width = get_window_width();
    EM_ASM({
      var canvas = document.createElement('canvas');
      canvas.id = 'canvas';
      canvas.height = window.innerHeight;
      canvas.width = window.innerWidth;
      document.body.appendChild(canvas);
    });
  }
} draw;