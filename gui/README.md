# 图形界面技术

以下的每个技术，学习周期至少都是季度级别的。

- `Qt`：跨平台的C++应用程序开发框架；
- `VCL`：Visual Component Library。Borland的技术，用于Borland C++ Builder，比MFC好用好多。影响了后来的WindowForm。
- `WinForm`：.Net的图形界面技术，使用简单，功能强大。
- `UWP`：目前主推的方案，此软件平台的目的是帮助发展Metro样式的应用程序。UWP应用程序不能在早期的Windows版本上运行；
- `MFC`：Microsoft Foundation Classes微软基础类。专门为VC设计的应用程序框架和引擎，以C++类的形式封装了Windows API，并且包含一个应用程序框架。缺点是“概念多、晦涩难懂、代码量大、界面也丑”；
- `ATL`：ActiveX Template Library活动模板库，一个产生C++/COM代码的框架，完全面向COM组件。比MFC精简；
- `WTL`：Windows Template Library，构架于ATL之上，采用C++模板技术来包装大部分窗口控制，并给出一个与MFC相似的应用框架；
- `WPF`：基于XML、.NET Framework、向量绘图技术的展示层开发框架。WPF使用一种新的XAML（eXtensible Application Markup Language）语言来开发界面。用于取代MFC的替代方案，目前已被舍弃；
- `wxWidgets`：开放源代码且跨平台的对象工具集（widget toolkit）
- `AWT`：Java的平台独立的视窗系统
- `Xamarin`：跨平台开发软件，通过使用C#编写的共享代码库，开发人员通过Xamarin工具可使用原生用户界面编写原生的Android、iOS和Windows应用程序
- `OLE`：Object Linking and Embedding，对象连接与嵌入。允许应用程序作为软件“对象”（数据集合和操作数据的函数）彼此进行“连接”的机制；
- `COM`：Component Object Model，部件对象模型。功能独立的Windows组件，按需组合；
- `ActiveX`：微软在网络环境中的界面交互技术。

# 示例代码

以下代码并不能直接编译，仅供了解技术原理使用：

- [Windows SDK](windows_sdk.cpp)
- [MFC](mfc.cpp)

# 设计原则

- 面向对象；
- MVC：模型（Model）、视图（View）和控制器（Controller）；
- 消息队列驱动；

# 相关的大神

- Anders
- Danny

# 示例代码

使用Windows SDK创建一个窗口
```
int WinMain() {
    WNDCLASS wndclass;

    wndclass.style         = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc   = WndProc;
    wndclass.cbClsExtra    = 0;
    wndclass.cbWndExtra    = 0;
    wndclass.hInstance     = NULL;
    wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName  = NULL;
    wndclass.lpszClassName = "MainWndClass";

    RegisterClass(&wndclass);

    HWND hwnd = CreateWindow(
        "MainWndClass",
        "Window Title",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hInstance,
        NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
```

使用Gtk创建一个窗口
```
GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

gtk_window_set_title(window, "window title");
gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
gtk_window_set_default_size(window, 400, 300);
gtk_window_set_resizable(window, TRUE);
```

使用Qt创建一个窗口（C#的WindowForm类似）：
```
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel label("Hello, world!");
    label.show();
    return app.exec();
}
```

# 参考资料

- https://zh.wikipedia.org/wiki/MVC
- https://zh.wikipedia.org/wiki/Qt
- https://zh.wikipedia.org/wiki/MFC_(%E5%BE%AE%E8%BB%9F)
- https://zh.wikipedia.org/wiki/AWT
- https://zh.wikipedia.org/wiki/WxWidgets
- https://zh.wikipedia.org/wiki/Xamarin
- https://zh.wikipedia.org/wiki/UWP
- https://docs.microsoft.com/en-us/windows/win32/api/_winmsg/
- https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
- https://atlserver.codeplex.com/
- https://www.zhihu.com/question/23480014
- https://www.zhihu.com/question/35218485/answer/63932275
- http://www.cppblog.com/unixflanker25su/archive/2006/04/14/5540.html
- [《Borland传奇》](https://book.douban.com/subject/1027528/)