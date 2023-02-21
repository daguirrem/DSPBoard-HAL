% @author David A. Aguirre M. <daguirre.m@outlook.com>
% @brief Generador de header con coeficientes B para filtro pasabajos.
% @version r1.0
% @date 2023-02-19
% 
% @copyright MIT License, Copyright (c) 2022-2023 David A. Aguirre M. @n @n
%
% Permission is hereby granted, free of charge, to any person obtaining a copy
% of this software and associated documentation files (the "Software"), to deal
% in the Software without restriction, including without limitation the rights
% to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
% copies of the Software, and to permit persons to whom the Software is
% furnished to do so, subject to the following conditions: @n @n
%
% The above copyright notice and this permission notice shall be included in all
% copies or substantial portions of the Software. @n @n

% THE SOFTWARE IS PROVIDED  "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
% IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
% FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
% AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
% LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
% SOFTWARE.

% Antes de ejecutar este script, es necesario ejecutar filterDesigner, 
% diseñar todos los filtros que se desean y exportarlos con los siguentes
% nombres:
%  pasaBajos
%  pasaAltos
%  pasaBanda
%  rechazaBanda

clc

Filters = {};
Type = [];
str = "";

if(exist('pasaBajos','var'))
    Filters = [Filters; pasaBajos];
    Type = [Type; "low"];
end

if(exist('pasaAltos','var'))
    Filters = [Filters; pasaAltos];
    Type = [Type; "high"];
end

if(exist('pasaBanda','var'))
    Filters = [Filters; pasaBanda];
    Type = [Type; "pass"];
end

if(exist('rechazaBanda','var'))
    Filters = [Filters; rechazaBanda];
    Type = [Type; "stop"];
end

if(isempty(Filters))
    disp("No se han encontrado coeficientes en las variables:");
    disp("pasaBajos, pasaAltos, pasaBanda o rechazaBanda");
    disp(" ");
    disp("Porfavor ejecute 'fitlerDesigner' y exporte los coeficientes generados a, almenos, una de las variables mencionadas");
    filterDesigner
    return
end

for k = 1 : length(Filters)
    str = strcat(str, sprintf("__CCM_VAR_I float b_%s[] = {\n    ", Type(k)));
    str_end = ", ";
    for i = 1 : length(Filters{k}) - 1
        if (i == (length(Filters{k}) - 1))
            str_end = "";
        end
        str = strcat(str, sprintf("%+0.5f%s", Filters{k}(i), str_end));
        if (mod(i,5) == 0 && i ~= (length(Filters{k}) - 1))
            str = strcat(str, sprintf("\n    "));
        end
    end
    str = strcat(str, sprintf("\n};\n\n"));
end

% https://la.mathworks.com/matlabcentral/answers/62986-how-to-change-a-specific-line-in-a-text-file
fid = fopen('template.h','r');
i = 1;
tline = fgetl(fid);
A{i} = tline;
while ischar(tline)
    i = i+1;
    tline = fgetl(fid);
    A{i} = tline;
end
fclose(fid);

A{40} = sprintf('#define FIR_ORDER %d', length(Filters{1})-1);
A{46} = sprintf('%s', str);

fid = fopen('fir_coeff.h', 'w');
for i = 1:numel(A)
    disp(A{i+1});
    if A{i+1} == -1
        fprintf(fid,'%s', A{i});
        break
    else
        fprintf(fid,'%s\n', A{i});
    end
end