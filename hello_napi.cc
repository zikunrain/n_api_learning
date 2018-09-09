// hello.cc using N-API
#include <node_api.h>
#include "accumulation.hpp"
#include <iostream>

using namespace std;

namespace demo {
  
napi_value SolveApi(napi_env env, napi_callback_info info) {
  // argc: the count of arguements
  size_t argc = 2;
  // declare an array for arguments
  napi_value args[2];
  napi_status status;

  // retrieve details about the call like the arguments
  status = napi_get_cb_info(env, info, &argc, args, NULL, NULL);  
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to retrieve the arguments");
  }
 
  // create an array to store arguments in napi
  napi_value ret;
  status = napi_create_array(env, &ret);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to create an array");
  }

  // argument have a structure like [[a, ,b ,c, ...], ]
  uint32_t i, length;
  int nAttr;

  // get the length of attrs of an entry
  status = napi_get_value_int32(env, args[1], &nAttr);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to get the length of attrs");
  }

  // get the length of enties
  status = napi_get_array_length(env, args[0], &length);
  if (status != napi_ok) {
    napi_throw_error(env, NULL, "Unable to get the length of enties");
  }

  int nEntries = int(length);
  // status = napi_get_value_int32(env, length, &nEntries)
  double** mvdata = new double* [nEntries];
  for (int i = 0; i < nEntries; i++) {
    mvdata[i] = new double[nAttr];
  }

  // scan entries
  for (i = 0; i < length; i++) {
    napi_value entry;
    // get entry by index within argument
    status = napi_get_element(env, args[0], i, &entry);
    if (status != napi_ok) {
      napi_throw_error(env, NULL, "Unable to get entries");
    }
    
    napi_value attr;
    
    // napi_status = napi_get_array_length(env, entry, &nAttr)
    // if (status != napi_ok) {
    //   napi_throw_error(env, NULL, "Unable to get the length of attrs");
    // }
    uint32_t attrIndex;
    for (attrIndex = 0; int(attrIndex) < nAttr; attrIndex++) {
      status = napi_get_element(env, entry, attrIndex, &attr);
      double t = 0.0;
      status = napi_get_value_double(env, attr, &t);

      cout << int(i) << ' ' << int(attrIndex) << endl;

      cout << t << endl;
    }

    status = napi_set_element(env, ret, i, entry);
  }
  return ret;
}


napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, SolveApi, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "solve", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo