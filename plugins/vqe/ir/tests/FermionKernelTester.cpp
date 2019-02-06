
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
#include "FermionKernel.hpp"

using namespace xacc::vqe;

TEST(FermionKernelTester,checkFermionKernelConstruction) {

	auto Instruction = std::make_shared<FermionInstruction>(
			std::vector<std::pair<int, int>> { { 4, 1 }, { 3, 1 }, { 9, 0 }, {
					1, 0 } });
	auto Instruction2 = std::make_shared<FermionInstruction>(
			std::vector<std::pair<int, int>> { { 2, 1 }, { 1, 1 }, { 3, 0 }, {
					1, 0 } });
	auto Instruction3 = std::make_shared<FermionInstruction>(
			std::vector<std::pair<int, int>> { { 5, 1 }, { 3, 1 }, { 6, 0 }, {
					4, 0 } }, 33.3);

	FermionKernel kernel("foo");
	kernel.addInstruction(Instruction);
	kernel.addInstruction(Instruction2);
	kernel.addInstruction(Instruction3);

	EXPECT_TRUE(kernel.nInstructions() == 3);
	EXPECT_TRUE(kernel.name() == "foo");
	EXPECT_TRUE(kernel.getInstruction(0) == Instruction);
	EXPECT_TRUE(kernel.getInstruction(1) == Instruction2);
	EXPECT_TRUE(kernel.getInstruction(2) == Instruction3);

	std::cout << kernel.toString("") << "\n";

}

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
