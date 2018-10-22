#if !defined(HELLO_WORLD_H)
#define HELLO_WORLD_H

#include <fruit/fruit.h>
#include <string>

namespace hello_world {

    class Writer {
    public:
        virtual std::string write(std::string s) = 0;
    };

    class StdoutWriter : public Writer {
    public:
        // Like "StdoutWriter() = default;" but also marks this constructor as the one to use for injection.
        INJECT(StdoutWriter()) = default;

        virtual std::string write(std::string s) override {
        return s;
        }
    };

    class Greeter {
    public:
        virtual std::string greet() = 0;
    };

    class GreeterImpl : public Greeter {
    private:
        Writer* writer;

    public:
        // Like "GreeterImpl(Writer* writer) : ... {...}" but also marks this constructor as the one to use for injection.
        INJECT(GreeterImpl(Writer* writer))
            : writer(writer) {
        }

        virtual std::string greet() override {
            return writer->write("Hello, World!");
        }
    };

    fruit::Component<Greeter> getGreeterComponent() {
        return fruit::createComponent()
            .bind<Writer, StdoutWriter>()
            .bind<Greeter, GreeterImpl>();
    }

}

#endif
