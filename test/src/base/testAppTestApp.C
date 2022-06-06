//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "testAppTestApp.h"
#include "testAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
testAppTestApp::validParams()
{
  InputParameters params = testAppApp::validParams();
  return params;
}

testAppTestApp::testAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  testAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

testAppTestApp::~testAppTestApp() {}

void
testAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  testAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"testAppTestApp"});
    Registry::registerActionsTo(af, {"testAppTestApp"});
  }
}

void
testAppTestApp::registerApps()
{
  registerApp(testAppApp);
  registerApp(testAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
testAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testAppTestApp::registerAll(f, af, s);
}
extern "C" void
testAppTestApp__registerApps()
{
  testAppTestApp::registerApps();
}
