#include <X11/Xlib.h>
#include <unistd.h>
#include <stdlib.h>

void move_mouse(Display *display, int x, int y) {
    Window root = DefaultRootWindow(display);
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XFlush(display);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        return 1;
    }

    move_mouse(display, x, y);
    XCloseDisplay(display);

    return 0;
}
