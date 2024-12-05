#include <array>

#include <Python.h>

namespace {

#define slot(s, v)                                                             \
  PyModuleDef_Slot {                                                           \
    s, reinterpret_cast<void*>(v)                                              \
  }

std::array nrmod_slots {
    slot(Py_mod_multiple_interpreters, Py_MOD_PER_INTERPRETER_GIL_SUPPORTED),
    slot(Py_mod_gil, Py_MOD_GIL_NOT_USED),
    PyModuleDef_Slot {},
};

#undef slot

PyModuleDef pycmaketest_mod {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "pycmaketest",
    .m_doc = "Test of py-build-cmake",
    .m_slots = nrmod_slots.data(),
};
} // namespace

PyMODINIT_FUNC PyInit_nanoroute() {
  return PyModuleDef_Init(&pycmaketest_mod);
}
