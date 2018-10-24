#include <iostream>
#include <string>

using namespace std;

class A{
protected:
    class X {
    private:
        string x;

    public:
        virtual void show(){
            cout << "X{ x = \'" << x << "\' }" << endl;
        }

        X(){};

        X(string someX) : x(someX) {};

        string get(){return x;}
    };
    string a;
    X *objectX;
    
public:
    A(string someA) : a(someA) {objectX = new X("xxx");};

    A(){objectX = new X("xxx");};

    ~A(){
        delete objectX;
    }

    virtual void set(string someString) {a = someString;};

    virtual void showField(){
        cout << "There was an idea to bring together a group of remarkable people." << a << endl;
    } 

    virtual void show(){
        cout << "A{ a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl; 
    }
};

class B : public A{
protected:
    string b;

public:
    B(){};

    virtual void set(string someString) {b = someString;};

    virtual void show(){
        cout << "B{ b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;  
    }

    virtual void showField(){
        cout << "Bill Cypher is always one step forward." << b << endl;
    } 

    B(string someB) : b(someB){};
};

class C : public B{
protected:
    string c;

public:
    C(string someC) : c(someC){};

    C(){};

    virtual void set(string someString) {c = someString;};

    virtual void showField(){
        cout << "Language, Stark." << c << endl;
    }

    virtual void show(){
        cout << "C{ c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class D : public C{
protected:
    string d;

public:
    D(string someD) : d(someD) {};

    D(){};

    virtual void set(string someString) {d = someString;};

    virtual void showField(){
        cout << "Well, the marked one, I saved you and I'm not too noble." << d << endl;
    }

    virtual void show(){
        cout << "D{ d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class E : public D{
protected:
    string e;

public:
    E(string someE) : e(someE) {};

    E(){};

    virtual void set(string someString) {e = someString;};

    virtual void showField(){
        cout << "Kifflom, brother brother." << e << endl;
    }

    virtual void show(){
        cout << "E{ e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class F : public E{
protected:
    string f;

public:
    F(string someF) : f(someF) {};

    F(){};

    virtual void set(string someString) {f = someString;};
    virtual void showField(){
        cout << "It is just a joke... Simple bad joke..." << f << endl;
    }

    virtual void show(){
         cout << "F{ f = \'" << f << "\', e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class G : public F{
protected:
    string g;

public:
    G(string someG) : g(someG) {};

    G(){};

    virtual void set(string someString) {g = someString;};

    virtual void showField(){
        cout << "Our salvation is inside." << g << endl;
    }

    virtual void show(){
        cout << "G{ g = \'" << g << "\', f = \'" << f << "\', e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class H : public G{
protected:
    string h;

public:
    H(string someH) : h(someH) {};

    H(){};

    virtual void set(string someString) {h = someString;};

    virtual void showField(){
        cout << "With great power comes great responsability." << h << endl;
    }

    virtual void show(){
        cout << "H{ h = \'" << h << "\', g = \'" << g << "\', f = \'" << f << "\', e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class I : public H{
protected:
    string i;

public:
    I(string someI) : i(someI) {};

    I(){};

    virtual void set(string someString) {i = someString;};

    virtual void showField(){
        cout << "I will wait for you till next summer." << i << endl;
    }

    virtual void show(){
        cout << "I{ i = \'" << i << "\', h = \'" << h << "\', g = \'" << g << "\', f = \'" << f << "\', e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

class J : public I{
protected:
    string j;

public:
    J(string someJ) : j(someJ){};

    J(){};

    virtual void set(string someString) {j = someString;};

    virtual void showField(){
        cout << "John was writing letters to her every day entire year." << j << endl;
    }

    virtual void show(){
        cout << "J{ j = \'" << j << "\', i = \'" << i << "\', h = \'" << h << "\', g = \'" << g << "\', f = \'" << f << "\', e = \'" << e << "\', d = \'" << d << "\', c = \'" << c << "\', b = \'" << b << "\', a = \'" << a << "\', x = \'" << objectX->get() << "\' }" << endl;
    }
};

int main(){
    A aa;
    B bb;
    C cc;
    D dd;
    E ee;
    F ff;
    G gg;
    H hh;
    I ii;
    J jj;

    aa.show();
    bb.show();
    cc.show();
    dd.show();
    ee.show();
    ff.show();
    gg.show();
    hh.show();
    ii.show();
    jj.show();

    aa.set(" - Avengers");
    bb.set(" - Gravity Falls");
    cc.set(" - Avengers: Age Of Ultron");
    dd.set(" - S.T.A.L.K.E.R.: Shadow Of Chernobyl");
    ee.set(" - GTA V");
    ff.set(" - Watchmen");
    gg.set(" - Shawshank Redemption");
    hh.set(" - Spider-Man");
    ii.set(" - I Know What You Did Last Summer");
    jj.set(" - Diary of Memory");

    aa.showField();
    bb.showField();
    cc.showField();
    dd.showField();
    ee.showField();
    ff.showField();
    gg.showField();
    hh.showField();
    ii.showField();
    jj.showField();
}