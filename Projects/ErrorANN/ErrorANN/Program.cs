using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ErrorANN
{
    class Program
    {

   
        static void Main(string[] args)
        {


            //Variables
            double[,] Input = new double[300, 608];//Matriz donde van numeros
            double[,] Output = new double[300,1];//Matriz donde van numeros
            double[,] OutputNN = new double[300, 1];//Matriz donde van numeros
            double[,] weightsInput = new double[50, 608];//Matriz donde van numeros
            double[,] weightsOutput = new double[1, 50];//Matriz donde van numeros
            List<double> hidden = new List<double>(new double[50] ); //estado interno neuronas en la capa oculta
            List<double> output = new List<double>(new double[1]); //estado interno neuronas en la capa de salida
            int examples = 300;//Numero de datos para probar
            int hiddenNeurons = 50;//numeo de neuronas en la capa oculta
            int outputNeurons = 1;//numero de neuronas en la capa de salida
            int features = 608;

                       
            /////////////////////////Lectura pesos entrada///////////////////////////
            weightsInput = extract(@"C:\pesosNeuronasCapaOculta.csv", 50, 608);

            ////////////////////////Lectura pesos salida//////////////////////////////  
                       
            weightsOutput = extract(@"C:\pesosNeuronaSalida1x50.csv",1,50);

            ////////////////////////Lectura Datos entrada////////////////////////////// 
            Input = extract(@"C:\DATOS300x608CARACTERISTICAS.csv", 300, 608);

            ////////////////////////Lectura Datos salida////////////////////////////// 
            Output = extract(@"C:\salidaDatosPrueba300x1.csv", 300,1);

            int error=0;

            for (int i = 0; i < examples; i++)
            {
                Calc_Activation(i, weightsInput, weightsOutput, hidden, output, hiddenNeurons, outputNeurons, Input, features);

              if (output[0] > 0.8) output[0] = 1;
              if (output[0] < 0.5) output[0] = 0;

         
              if (output[0] != Output[i, 0])
              {
                  error = error + 1;
                 // Console.WriteLine(output[0]);
                 // Console.WriteLine(Output[i, 0]);
              }

                for(int j=0; j<50;j++)hidden[j]=0;
                for (int j = 0; j < 1; j++) output[j] = 0;

                              
              //hidden.Clear();
             // output.Clear();

            }



            Console.WriteLine("errores de clasificacion");
            Console.WriteLine(error);//solo es para comprobar
            Console.ReadLine();//espera hasta que se presione una tecla

        }



        /***************************************************************************************************
    Metodos
    Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
    Descripcion: Extrae en variales informacion de un csv

    ***************************************************************************************************/
        static public double[,] extract(String ruta,int filas, int columnnas)
        {
            var reader = new StreamReader(File.OpenRead(ruta));//archivo csv 
            int fila = 0;//contador para filas de matriz
            double[,] weightsInput = new double[filas, columnnas];//Matriz donde van numeros

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
               
                
            }

            return weightsInput;

        }



        /***************************************************************************************************
      Metodos
      Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
      Descripcion: Evalua la entrada en la funcion sigmoide

      ***************************************************************************************************/
        static private double sigmoid(double x)
        {
            return 1 / (1 + Math.Exp(-x));
        }


        /***************************************************************************************************
        Metodos
        Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
        Descripcion: Calcula la salida de una red neuronal de 1 capa oculta

        ***************************************************************************************************/

        static private void Calc_Activation(int train, double[,] weightsInput, double[,] weightsOutput, List<double> hidden, List<double> output, int hiddenNeurons, int outputNeurons, double[,] inputsToNetwork, int features)
        {
            // Iteración entre el conjunto de activaciones en la capa oculta.
            
            for (int ch = 0; ch < hiddenNeurons ; ch++ )
            {

                
                for (int ci = 0; ci < features; ci++)
                    hidden[ch] += inputsToNetwork[train, ci] * weightsInput[ch, ci];//para cada neurona ch acumula las entradas ci

                
            }
            // calcular la salida de la capa oculta
            for (int x = 0; x < hiddenNeurons; x++)
            {
                hidden[x] = sigmoid(hidden[x]);//evalua en la sigmoide
            }
            // Iteración entre el conjunto de activaciones en la capa de salida.
            int co = 0;
            while (co < outputNeurons )
            {
                for (int chi = 0; chi < hiddenNeurons ; chi++)
                    output[co] += hidden[chi] * weightsOutput[co, chi];//para cada neurona co acumula las entradas chi
                co++;
            }
            // Calcular la salida de la capa de Salida
            for (int x = 0; x < outputNeurons; x++)
            {
                output[x] = sigmoid(output[x]);//evalua en la sigmoide
            }
        } 

    }
}
