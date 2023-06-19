#include <thread>
#include <string>

void open_document_and_display_gui(std::string const& filename)
{}

bool done_editing()
{
    return true;
}

enum command_type{
    open_new_document
};


struct user_command
{
    command_type type;

    user_command():
        type(open_new_document)
    {}
};

user_command get_user_input()
{
    return user_command();
}

std::string get_filename_from_user()
{
    return "foo.doc";
}

void process_user_input(user_command const& cmd)
{}

void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);
    while(!done_editing())
    {
        user_command cmd=get_user_input();
        if(cmd.type==open_new_document)
        {
            // 假设用户在这里打开了一个新文档，就可以通过复用edit_document()方法来编辑新文档
            // 线程参数以右值引用的方式传递，因为线程会保存对参数的引用，所以必须确保该参数在新线程结束之前一直存在
            std::string const new_name=get_filename_from_user();
            std::thread t(edit_document,new_name);
            t.detach();
            /* 
            1. 因此，传递局部变量是不安全的，例如
            char buffer[1024];
            sprintf(buffer,"%s","foo.doc");
            std::thread t2(edit_document,buffer); // 可能发生未定义行为
            这里buffer指针被传递到线程，但线程中访问指针指向内容的时候，buffer可能已经被销毁了。
            2. 传递临时对象是安全的，例如
            std::thread t3(edit_document,std::string("foo.doc"));
            3. 传递堆上的对象也是安全的，例如
            std::thread t4(edit_document,new std::string("foo.doc"));
            4. 传递引用是无法通过编译的，例如
            void update_data_for_widget(widget_id w,widget_data& data);
            void oops_again(widget_id w) {
                widget_data data;
                std::thread t(update_data_for_widget,w,data); // 编译错误
                t.join();
            }
            这里的data会被拷贝到新线程的内部存储空间中，然后右值传递，
            但是update_data_for_widget()方法期望的是一个左值引用，所以编译器会报错。
            解决：可以通过C++11的std::ref()方法来解决这个问题，例如:
            std::thread t(update_data_for_widget,w,std::ref(data)); // 传递的是引用而不是拷贝

            */
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main()
{
    edit_document("bar.doc");
}
