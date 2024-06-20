#include <emscripten.h>
using namespace std;

class draw_canvas {
  // canvasを使用する
  int height,width;
  EM_JS(int,get_window_height,(),{
    return window.innerHeight;
  });
  EM_JS(int,get_window_height,(),{
    return window.innerHeight;
  });
  draw_canvas() : height(get_window_height()), width(get_window_width()) {
    EM_ASM("
      var canvas = document.createElement('canvas');
      canvas.id = 'canvas';
      canvas.height = window.innerHeight;
      canvas.width = window.innerWidth;
      document.body.appendChild(canvas);
    ");
  }
} draw;