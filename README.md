# alpha-beta-coordination
Collective search by mobile robots using alpha-beta coordination

This repository contains an implementation of the concept introduced in
[this](https://www.osti.gov/servlets/purl/645499) paper.

## Overview

Given a search space where a team of mobile robots is required to aggregate around an area with the highest intensity of a phenomenon, an alpha-beta coordination system can allow the team to achieve this objective effectively.

The concept primarily involves the divison of the team into two main categories or sets, _alpha_ and _beta_. _Alpha_ agents are risk takers, and
are motivated to improve their position in the area by taking aggressive steps. _Beta_ agents also are motivated to improve their position, but do
so in a much more conservative manner. The combined use of both _alpha_ and _beta_ agents allows the system to perform well to achieve the specified objective and present a unique approach to solving the problem.

The quality of the position of an agent is determined based on the application. For example, if the team is tasked with aggregating around the region with the highest concentration of a chemical, then the quality of the position would be determined by the intensity at which the agent
senses the chemical (greater the intensity, closer the agent is to the target, hence better the position).

## Concept

For a team of N mobile agents, the M agents with the best position make up the alpha set A. The
remaining N-M agents make up the beta set B. Every iteration, agents in A and B update their position based on an update rule that is decided by which set they are in.

The agent with the best position in the entire team is labelled Φ-alpha.

#### Update rules

1. If an agent is Φ-alpha, then it adopts a conservative strategy and remains stationery.
2. If an agent belongs to A, then its velocity is directly towards Φ-alpha.
3. If an agent is part of B, then its velocity is the combination of a pull towards each agent in A, and push away from each agent in B.
