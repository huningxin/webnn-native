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

#ifndef WEBNN_NATIVE_IE_NEURAL_NETWORK_CONTEXT_IE_H_
#define WEBNN_NATIVE_IE_NEURAL_NETWORK_CONTEXT_IE_H_

#include "webnn_native/NeuralNetworkContext.h"

namespace webnn_native { namespace ie {

    class NeuralNetworkContext : public NeuralNetworkContextBase {
      public:
        NeuralNetworkContext() = default;
        ~NeuralNetworkContext() override = default;

        ModelBuilderBase* CreateModelBuilderImpl() override;

      private:
    };

}}  // namespace webnn_native::ie

#endif  // WEBNN_NATIVE_IE_NEURAL_NETWORK_CONTEXT_IE_H_
