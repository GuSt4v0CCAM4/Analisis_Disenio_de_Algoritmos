#import <mso9.dll> no_namespace rename("DocumentProperties","DocumentPropertiesXL")
// Importa la biblioteca mso9.dll sin especificar un espacio de nombres y renombra "DocumentProperties" como "DocumentPropertiesXL"

#import <vbe6ext.olb> no_namespace
// Importa la biblioteca vbe6ext.olb sin especificar un espacio de nombres

#import <excel9.olb>
// Importa la biblioteca excel9.olb

rename("DialogBox", "DialogBoxXL") \rename("RGB", "RBGXL") \rename("DocumentProperties", "DocumentPropertiesXL") \no_dual_interfaces
// Renombra "DialogBox" como "DialogBoxXL", "RGB" como "RBGXL" y "DocumentProperties" como "DocumentPropertiesXL". No utiliza interfaces duales.

#import <msword9.olb>
// Importa la biblioteca msword9.olb

rename("DialogBox", "DialogBoxWord") \rename("RGB", "RBGWord") \rename("DocumentProperties", "DocumentPropertiesWord") \no_dual_interfaces
// Renombra "DialogBox" como "DialogBoxWord", "RGB" como "RBGWord" y "DocumentProperties" como "DocumentPropertiesWord". No utiliza interfaces duales.

namespace MyNS
{
    int gnCount; // Contador global
    // Algunas funciones pequeñas implementadas en línea

    double Addition(double a, double b) // Función global
    {
        return a+b;
    }

    // Algunos prototipos

    long factorial(int n); // Función global

    class CTest
    {
    public:
        Test();
        void Method1();
    };

    // Aquí van más variables, funciones, métodos, clases, estructuras
};
