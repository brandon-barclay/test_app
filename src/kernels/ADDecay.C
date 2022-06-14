#include "ADDecay.h"

registerMooseObject("TestAppApp", ADDecay);

InputParameters
ADDecay::validParams()
{
  InputParameters params = ADKernel::validParams();
  params.addClassDescription("Kernel to compute the radionuclide decay");
  return params;
}

ADDecay::ADDecay(const InputParameters & params)
: ADKernel(params),
  _decay_constant(getMaterialProperty<Real>("decay_constant"))
  {
  }

ADReal
ADDecay::computeQpResidual()
{
  return - _test[_i][_qp] * _decay_constant[_qp] * _u[_qp];
}
