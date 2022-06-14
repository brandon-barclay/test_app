[Mesh]
  type = GeneratedMesh
  dim = 2
  xmin = 0
  xmax = 1
  ymin = 0
  ymax = 1
  nx = 250
  ny = 250
  elem_type = QUAD4
[]

[Variables]
  [concentration]
  []
[]

[Functions]
  [variablePoint]
    type = ParsedFunction
    value = sin(t)
  []
[]

[Kernels]
  [Diffusion]
    type = ADDiffusion
    variable = concentration
  []
  [Advection]
    type = ConservativeAdvection
    variable = concentration
    velocity = '0.2 0 0'
    upwinding_type = full
  []
  [Time]
    type = MassLumpedTimeDerivative
    variable = concentration
  []
[]

[DiracKernels]
  [source]
    type = ConstantPointSource
    variable = concentration
    #function = variablePoint
    value = 1
    point = '0.2 0.1 0'
  []
[]

[BCs]
  [diffusionFlux]
    type = DiffusionFluxBC
    variable = concentration
    boundary = 'top bottom left right'
  []
[]

[Materials]
[]

[Executioner]
  type = Transient
  solve_type = 'NEWTON'
  num_steps = 100
  dt = 0.01
[]

[Outputs]
  execute_on = 'timestep_end'
  exodus = true
[]
