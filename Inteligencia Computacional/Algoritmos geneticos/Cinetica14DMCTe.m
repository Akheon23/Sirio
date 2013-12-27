function F = Cinetica14DMCTe (x)

%Minimizacion del error relativo entre el valor experimental (yexp)
%y el calculado (ycalc).

%Mecanismo Propuesta 9, paso 5 limitante, adsorcion no competitiva.

%clc
%clear all
%x=[1e-3,1e-5,1e5,1e4,1e-4,1e6,1e3,1e-3,1e-5]
load DatosDMC2.txt
salir=0;

Pmet = DatosDMC2(1,:);
PCO2 = DatosDMC2(2,:);
Pdmc = DatosDMC2(3,:);
Pw = DatosDMC2(4,:);
T = DatosDMC2(5,:);
%rexp = DatosDMC2(6,:);
vo = (DatosDMC2(7,:))./60000;
yexp = DatosDMC2(8,:);


R = 8.3143;

k5 = x(1)*exp(-x(2)./(R*T));

K1 = exp(-x(3)./(R*T))  ;   %  4.87e-2

K2 = exp(-x(4)./(R*T)) ;    %  6.12e12
 
K3 = exp(-x(5)./(R*T));

K4 = exp(-x(6)./(R*T)) ;   % 4.87e-11          

K5 = exp(-x(7)./(R*T));    % 1.72e-8

K6 = exp(-x(8)./(R*T)) ;   % 1.45e12

K7 = exp(-x(9)./(R*T));

Beta = (1./((K1.^2).*K2.*K3.*K4.*K5.*K6.*K7)).*(Pdmc.*Pw./((Pmet.^2).*PCO2));


for n = 1:11
    
    a = Pdmc.*Pw./(K1.*K3.*K6.*K7.*Pmet);
    b = 1+(K4.*PCO2);
    c = 1+(K1.*Pmet)+(K1.*K2.*Pmet)+(K1.*K3.*K7.*Pmet./Pw)+(Pw./K7);
    
    Cuadratica = [(a(n).*c(n)) (b(n).*c(n)) -b(n)];
    raices(n,:) = roots(Cuadratica);
    
   s(1) = raices(n,1);
   s(2) = raices(n,2);

    
    if s(1)>=0 & s(1)<=1
    ThetaA(n) = s(1);
    
    elseif s(2)>=0 & s(2)<=1
    ThetaA(n) = s(2);
    
    else
    ThetaA(n) = 1e-3 %ESTO SOLO LO PUSO PARA PENALIZAR LOS X QUE LE GENERARON RAICES MEJOR DEJARLO COMO QUE SI PASA ESTO PENALIZA LAS X DIRECTAMETE EN EL F
    salir= 1;
    end

end

ThetaB = 1./((a.*ThetaA)+b);

rcalc = (k5.*K1.*K2.*K4.*Pmet.*PCO2.*ThetaA.*ThetaB).*(1-Beta);

ycalc = (2.*rcalc./vo).*(0.0082.*T/12);

%Funcion a minimizar:
if salir==1
   F=10e20;
else
F = sum(abs((yexp-ycalc)./yexp));
end

end