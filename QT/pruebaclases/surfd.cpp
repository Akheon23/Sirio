#include "surfd.h"

SurfD::SurfD()
{
}

SurfD::~SurfD()
{
}




/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Halla los descriptores Surf de la imagen ingresada y los devuelve en un vector

***************************************************************************************************/

cv::Mat SurfD::getSurfDescriptors(Mat M_imgSource)
{

    surf.detect(M_imgSource,V_vectKeypoints);
    surfDesc.compute(M_imgSource,V_vectKeypoints,M_vectDescriptors);
    return M_vectDescriptors;
}
