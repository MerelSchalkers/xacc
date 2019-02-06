/***********************************************************************************
 * Copyright (c) 2016, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include <gtest/gtest.h>
#include "FermionInstruction.hpp"
#include "InstructionParameter.hpp"

using namespace xacc::vqe;

bool operator==(const xacc::InstructionParameter p, const xacc::InstructionParameter q) {
    return p.toString() == q.toString();
}
TEST(FermionInstructionTester,checkConstruction) {

	// make a4dag a3dag a9 a1
	FermionInstruction inst(std::vector<std::pair<int, int>> { { 4, 1 },
			{ 3, 1 }, { 9, 0 }, { 1, 0 } });

	EXPECT_TRUE(inst.bits().size() == 4);
	EXPECT_TRUE(inst.getParameters().size() == 6);

	EXPECT_TRUE((inst.bits() == std::vector<int> {4, 3, 9, 1}));
	// EXPECT_TRUE((
	// 		inst.getParameters() == std::vector<xacc::InstructionParameter> {
	// 			xacc::InstructionParameter(1), xacc::InstructionParameter(1),
	// 					xacc::InstructionParameter(0),
	// 					xacc::InstructionParameter(0),
	// 					xacc::InstructionParameter(std::complex<double>(1.0)),
	// 					xacc::InstructionParameter(std::string(""))}));

	std::cout << "HEY:\n" << inst.toString("") << "\n";
}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

