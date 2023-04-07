#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main(void)
{
    char c;
    int v;
    while (!kbhit())
        puts("Press a key!  ");
    c = getchar();
    v = (int)c;
    printf("\nInteger value=%d", v);
    switch (v)
    {
    case 27:
        printf("\nEsc Pressed");
        break;
    case 32:
        printf("\nSpace Pressed");
        break;
    case 10:
        printf("\nEnter Pressed");
        break;
    case 9:
        printf("\nTab Pressed");
        break;
    case 72:printf("\nUp arrow Pressed");break;
    case 80:printf("\nDown arrow Pressed");break;
    case 75:printf("\nLeft arrow Pressed");break;
    case 77:printf("\nRight arrow Pressed");break;
    default:
        printf("\n%c Pressed", c);
        break;
    }
    return 0;
}