/*
 * Tencent is pleased to support the open source community by making ScriptX available.
 * Copyright (C) 2021 THL A29 Limited, a Tencent company.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <string>
#include "../../../src/types.h"

#ifdef __PRETTY_FUNCTION__

#define TEMPLATE_NOT_IMPLEMENTED() \
  throw Exception(std::string(__PRETTY_FUNCTION__) + " not implemented")

#else

#define TEMPLATE_NOT_IMPLEMENTED() throw Exception(std::string(__func__) + " not implemented");

#endif

namespace script {

namespace wasm_backend {
class WasmEngine;
}

template <>
struct internal::ImplType<ScriptEngine> {
  using type = wasm_backend::WasmEngine;
};

}  // namespace script