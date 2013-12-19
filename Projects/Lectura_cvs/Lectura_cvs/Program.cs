using System;
using System.Collections.Generic;
using System.Linq;
/*Algoritmo para extraer strings separados en este caso por ";" y colocarlos en una matriz
*/
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lectura_cvs
{
    class Program
    {
        

        static void Main(string[] args)
        {

            double[,] weightsInput = new double[50, 608];//Matriz donde van numeros

            var reader = new StreamReader(File.OpenRead(@"C:\pesosNeuronasCapaOculta.csv"));//archivo csv  
                      
            int fila = 0;//contador para filas de matriz
            while (!reader.EndOfStream)
            {
               
                var line = reader.ReadLine();//lee linea a linea el archivo
                var values = line.Split(';');//separa la linea por ; entre palabras

                int contador = 0;//contador para columnas de matriz
                
                foreach (var value in values)
                {
                    
                    weightsInput[fila, contador] = Convert.ToDouble(value);//asigna a la matriz un double que extrae de un string
                    contador = contador + 1;
                   
                }
                fila = fila + 1;
               // Console.WriteLine(fila);//escribe el numero de fila en la que va

                
            }

           // Console.WriteLine(weightsInput[19,1]);//solo es para comprobar
            Console.ReadLine();//espera hasta que se presione una tecla
        }
    }
}
