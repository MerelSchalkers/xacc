import xaccvqe as vqe
import xacc
from xaccvqe import PauliOperator
import unittest

class ComputeEnergyTest(unittest.TestCase):
     def testExecuteComputeEnergy(self):
        src = """__qpu__ kernel() {
   0.7137758743754461
   -1.252477303982147 0 1 0 0
   0.337246551663004 0 1 1 1 1 0 0 0
   0.0906437679061661 0 1 1 1 3 0 2 0
   0.0906437679061661 0 1 2 1 0 0 2 0
   0.3317360224302783 0 1 2 1 2 0 0 0
   0.0906437679061661 0 1 3 1 1 0 2 0
   0.3317360224302783 0 1 3 1 3 0 0 0
   0.337246551663004 1 1 0 1 0 0 1 0
   0.0906437679061661 1 1 0 1 2 0 3 0
   -1.252477303982147 1 1 1 0
   0.0906437679061661 1 1 2 1 0 0 3 0
   0.3317360224302783 1 1 2 1 2 0 1 0
   0.0906437679061661 1 1 3 1 1 0 3 0
   0.3317360224302783 1 1 3 1 3 0 1 0
   0.3317360224302783 2 1 0 1 0 0 2 0
   0.0906437679061661 2 1 0 1 2 0 0 0
   0.3317360224302783 2 1 1 1 1 0 2 0
   0.0906437679061661 2 1 1 1 3 0 0 0
   -0.4759344611440753 2 1 2 0
   0.0906437679061661 2 1 3 1 1 0 0 0
   0.3486989747346679 2 1 3 1 3 0 2 0
   0.3317360224302783 3 1 0 1 0 0 3 0
   0.0906437679061661 3 1 0 1 2 0 1 0
   0.3317360224302783 3 1 1 1 1 0 3 0
   0.0906437679061661 3 1 1 1 3 0 1 0
   0.0906437679061661 3 1 2 1 0 0 1 0
   0.3486989747346679 3 1 2 1 2 0 3 0
   -0.4759344611440753 3 1 3 0
}"""
        op = vqe.compile(src)
        buffer = xacc.getAccelerator('tnqvm').createBuffer('q',4)
        self.assertAlmostEqual(vqe.execute(op, buffer, **{'task':'compute-energy', \
        				'vqe-params':'0,-.0571583356234', \
        				'n-electrons':2}).energy, -1.13727, places=5)		
				
if __name__ == '__main__':
    xacc.Initialize(['--itensor-svd-cutoff','1e-16'])
    if xacc.hasAccelerator('tnqvm'):
       unittest.main() 
    xacc.Finalize()