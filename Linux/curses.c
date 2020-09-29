#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <curses.h>

typedef struct _Win {
    int x; // col
    int y; // row
    int w; // width
    int h; // lines
    char name[64];
    char title[64];
    WINDOW *win;
} Win;

Win win[3] = {
  // x,y,width,height,name,title,WINDOW*
  {0, 0, 60, 25, "L1", "", NULL}, 
  {60, 0, 20, 17, "R1", "", NULL}, 
  {60, 17, 20, 8, "R2", "", NULL}, 
};

// len(string) * sizeof(chtype)
char scr_string[640] = {0};
#define CH(s) str2chtype(s)

int init_screen()
{
  int ret = 0;
  initscr();

  for (int i = 0; i < 3; i++) {
    win[i].win = newwin(win[i].h, win[i].w, win[i].y, win[i].x);
    if (NULL == win) {
        printf("Init failed.\n");
        ret = -1;
        break;
    }
    scrollok(win[i].win, FALSE);
    clearok(win[i].win, TRUE);
    box(win[i].win, ACS_VLINE, ACS_HLINE);
    wrefresh(win[i].win);
  }

  return ret;
}

void refresh_all()
{
  for (int i = 0; i < 3; i++) {
    wrefresh(win[i].win);
  }
}

chtype* str2chtype(const char* str)
{
  size_t len = strlen(str)+1;
  chtype *ret = (chtype *)scr_string;
  memset(scr_string, 0, sizeof(scr_string));

  for (size_t i = 0; i < len; i++)
  {
    ret[i] = (chtype)str[i];
  }

  return ret;
}

void draw_text()
{
  mvwaddchstr(win[0].win, 12, 15, CH("Hello world!"));
  mvwaddch(win[1].win, 1, 1, 'H'); // erase old face

  refresh_all();
}

void cleanup()
{
    endwin();
    system("stty sane");
}

int main(int argc, char *argv[])
{
  init_screen();
  draw_text();
  getchar();
  cleanup();
  return 0;
}