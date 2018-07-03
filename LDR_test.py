from pyqtgraph.Qt import QtGui, QtCore       #importação de classes
import pyqtgraph as pg
import serial
import time
import scipy
import numpy as np


V=np.linspace(0.001,5,100)
#FMM Máquina Síncrona
R_aux=50000
#V=R*5/(R+R_aux)
#v*(R+R_aux)=5R
#V*R_AUX=R*(5-V)
#

R=R_aux*(V)/(5-V)
#Geração dos coeficientes da aproximação linear
p1=np.polyfit(np.array(V),np.array(R),2)
print()
#Geração de array de aproximação com dados de R_LDR
Vfit = p1[0]*V*V+p1[1]*V+p1[2]


app = QtGui.QApplication([])
view=pg.GraphicsWindow()
plot1 = view.addPlot()
plot1.addLegend()
plot1.setTitle("Curva de Tensão x R_LDR")
plot1.setLabel("bottom","Tensão (V)")
plot1.setLabel("left","Resistência do LDR (Ohms)")


curve1 = plot1.plot(pen='r',name="V=%.3f+%.3f*R_LDR+%.3f*R_LDR²"%(p1[2],p1[1],p1[0]))
curve2 = plot1.plot(pen='r')


view.show()

y1 = np.polyval(p1,V)

#curve1.setData(R,Vfit)
plot1.setYRange(100,100000)
curve2.setData(V,R)


if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_'):
        QtGui.QApplication.instance().exec_()
