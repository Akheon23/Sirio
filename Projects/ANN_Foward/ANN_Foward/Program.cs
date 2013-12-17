
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ANN_Foward
{
    class Program
    {


         
            List <double> inputsToNetwork; //caracteristicas de entrada a la red

            int features;
            int hiddenNeurons=100;//numeo de neuronas en la capa oculta
            int outputNeurons=2;//numero de neuronas en la capa de salida

            double[,] weightsInput = new double[100, 400];//pesos entrada capa oculta
            double[,] weightsOutput = new double[2, 3];//pesos salida capa oculta
           
            List<double> hidden; //estado interno neuronas en la capa oculta
            List<double> output; //estado interno neuronas en la capa de salida

            

            static void Main(string[] args)
            {
            }




        /***************************************************************************************************
        Metodos
        Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
        Descripcion: Evalua la entrada en la funcion sigmoide

        ***************************************************************************************************/
          private double sigmoid(double x)
            {
                        return 1/(1+Math.Exp(-x));
            }


        /***************************************************************************************************
        Metodos
        Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
        Descripcion: Calcula la salida de una red neuronal de 1 capa oculta

        ***************************************************************************************************/

        private void Calc_Activation()
        {
            // Iteración entre el conjunto de activaciones en la capa oculta.
            int ch = 0;
            while (ch < hiddenNeurons)
            {
                for (int ci = 0; ci <features; ci++)
                    hidden[ch] += inputsToNetwork[ci] * weightsInput[ch,ci];//para cada neurona ch acumula las entradas ci
                ch++;
            }
            // calcular la salida de la capa oculta
            for (int x = 0; x < hiddenNeurons; x++)
            {
                hidden[x] = sigmoid(hidden[x]);//evalua en la sigmoide
            }
            // Iteración entre el conjunto de activaciones en la capa de salida.
            int co = 0;
            while (co < outputNeurons)
            {
                for (int chi = 0; chi < hiddenNeurons; chi++)
                    output[chi] +=  hidden[chi] * weightsOutput[co,chi];//para cada neurona co acumula las entradas chi
                co++;
            }
            // Calcular la salida de la capa de Salida
            for (int x = 0; x < this.o; x++)
            {
                output[x] = sigmoid(output[x]);//evalua en la sigmoide
            }
        } 

    }




}


