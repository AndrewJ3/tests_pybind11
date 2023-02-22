#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/embed.h>
#include <vector>
using namespace pybind11::literals;
using namespace std;

namespace py = pybind11;


void test_fcn(){

//  py::initialize_interpreter();

//  py::object np = py::module::import("numpy");
//  py::array_t<float> arr = np.attr("ones")(3,"dtype"_a="float32");
  std::vector<double> a = {1,2,3,4};
  py::list list = py::cast(a);
  py::dict data;
  data["list"] = list;
//  py::array_t<float> arr = np.attr("ones");
  py::function test_flux = py::module::import("fcn_python").attr("run");
  test_flux(data);
  py::print("In CPP",data["sum"]);
}



int main(){
  test_fcn();
//  py::finalize_interpreter();

  return 0;
}
