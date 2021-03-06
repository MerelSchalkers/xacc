/*******************************************************************************
 * Copyright (c) 2017 UT-Battelle, LLC.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompanies this
 * distribution. The Eclipse Public License is available at
 * http://www.eclipse.org/legal/epl-v10.html and the Eclipse Distribution
 *License is available at https://eclipse.org/org/documents/edl-v10.php
 *
 * Contributors:
 *   Alexander J. McCaskey - initial API and implementation
 *******************************************************************************/
#ifndef QUANTUM_GATE_GATEIR_INSTRUCTIONS_RY_HPP_
#define QUANTUM_GATE_GATEIR_INSTRUCTIONS_RY_HPP_

#include "GateInstruction.hpp"

namespace xacc {
namespace quantum {
class Ry : public virtual GateInstruction {
public:
  Ry()
      : GateInstruction("Ry", std::vector<InstructionParameter>{
                                  InstructionParameter(0.0)}) {}

  Ry(int qbit, double theta)
      : GateInstruction(
            "Ry", std::vector<int>{qbit},
            std::vector<InstructionParameter>{InstructionParameter(theta)}) {}

  Ry(std::vector<int> qbits)
      : GateInstruction(
            "Ry", qbits,
            std::vector<InstructionParameter>{InstructionParameter(0.0)}) {}
  const int nRequiredBits() const override {return 1;}

  DEFINE_CLONE(Ry)
  DEFINE_VISITABLE()
};
} // namespace quantum
} // namespace xacc

#endif
