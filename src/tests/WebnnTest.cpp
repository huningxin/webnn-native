// Copyright 2021 The WebNN-native Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tests/WebnnTest.h"

static WebnnTestEnvironment* gTestEnv = nullptr;

void InitWebnnEnd2EndTestEnvironment() {
    gTestEnv = new WebnnTestEnvironment();
    testing::AddGlobalTestEnvironment(gTestEnv);
}

const webnn::NeuralNetworkContext& WebnnTest::GetContext() {
    return gTestEnv->GetContext();
}

void WebnnTest::SetUp() {
    const webnn::NeuralNetworkContext& context = GetContext();
    context.SetUncapturedErrorCallback(ErrorCallback, this);
}

WebnnTest::~WebnnTest() {
}

void WebnnTest::TearDown() {
    ASSERT_FALSE(mExpectError);
}

void WebnnTest::StartExpectContextError() {
    mExpectError = true;
    mError = false;
}
bool WebnnTest::EndExpectContextError() {
    mExpectError = false;
    return mError;
}

std::string WebnnTest::GetLastErrorMessage() const {
    return mErrorMessage;
}

void WebnnTest::ErrorCallback(WebnnErrorType type, char const* message, void* userdata) {
    ASSERT(type != WebnnErrorType_NoError);
    auto self = static_cast<WebnnTest*>(userdata);
    self->mErrorMessage = message;

    ASSERT_TRUE(self->mExpectError) << "Got unexpected error: " << message;
    ASSERT_FALSE(self->mError) << "Got two errors in expect block";
    self->mError = true;
}

void WebnnTestEnvironment::SetUp() {
    mContext = CreateCppNeuralNetworkContext();
    DAWN_ASSERT(mContext);
}

const webnn::NeuralNetworkContext& WebnnTestEnvironment::GetContext() {
    return mContext;
}