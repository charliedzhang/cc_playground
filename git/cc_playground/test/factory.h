#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <string>
#include <memory>
#include <functional>

class factory {
public:
    static factory& get_instance();

    template<typename T, typename ...Args>
    class add {
    public:
        add(Args&&... args);

        add(const std::string& name, Args&&... args);
    };

    template<typename T>
    static T* get(const std::string& name = "");

    void create();

    void destroy();
private:
    using destructor = std::function<void(void*)>;
    using object = std::unique_ptr<void, destructor>;
    using constructor = std::function<object(void)>;

    factory();

    factory(const factory& other) = delete;

    factory& operator=(const factory& other) = delete;

    void add_object(const std::string& name, constructor create);

    void* get_object(const std::string& name);

    std::map<std::string, constructor> m_constructors;
    std::map<std::string, object> m_objects;
};

template<typename T, typename ...Args>
factory::add<T, Args...>::add(Args&&... args) {
    add("", args...);
}

template<typename T, typename ...Args>
factory::add<T, Args...>::add(const std::string& name, Args&&... args) {
    factory::get_instance().add_object(name,
                                       [args...] () -> object {
                                           return object{
                                                   new T(std::forward<Args>(args)...),
                                                   [] (void* obj) {
                                                       delete static_cast<T*>(obj);
                                                   }
                                           };
                                       }
    );
}

template<typename T> auto
factory::get(const std::string& name) -> T* {
    return static_cast<T*>(factory::get_instance().get_object(name));
}

#endif /* FACTORY_HPP */