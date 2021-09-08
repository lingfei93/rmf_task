/*
 * Copyright (C) 2021 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef RMF_TASK__SEQUENCE__PHASES__PICKUP_HPP
#define RMF_TASK__SEQUENCE__PHASES__PICKUP_HPP

#include <rmf_traffic/agv/Planner.hpp>

#include <rmf_task/Payload.hpp>
#include <rmf_task/sequence/Phase.hpp>

namespace rmf_task {
namespace sequence {
namespace phases {

//==============================================================================
class PickUp
{
public:

  using Location = rmf_traffic::agv::Plan::Goal;

  class Description;
  class Model;
};

//==============================================================================
class PickUp::Description : public Phase::Description
{
public:

  /// Make a Pickup phase
  ///
  /// \param[in] pickup_location
  ///   The location that the robot needs to get to for the pickup
  ///
  /// \param[in] from_dispenser
  ///   The dispenser that will take care of loading the items. We will
  ///   communicate with this dispenser to verify the success of loading the
  ///   items.
  ///
  /// \param[in] payload
  ///   A description of should be loaded into the robot during the pick-up.
  ///
  /// \param[in] loading_duration_estimate
  ///   An estimate for how long it will likely take to load the items.
  static std::shared_ptr<Description> make(
    Location pickup_location,
    std::string from_dispenser,
    Payload payload,
    rmf_traffic::Duration loading_duration_estimate);

  // Documentation inherited
  Phase::ConstModelPtr make_model(
    State invariant_initial_state,
    const Parameters& parameters) const final;

  // Documentation inherited
  execute::Phase::ConstTagPtr make_tag(
    execute::Phase::Tag::Id id,
    const State& initial_state,
    const Parameters& parameters) const final;

  class Implementation;
private:
  rmf_utils::impl_ptr<Implementation> _pimpl;
};

} // namespace phases
} // namespace sequence
} // namespace rmf_task

#endif // RMF_TASK__SEQUENCE__PHASES__PICKUP_HPP