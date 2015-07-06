/*
 * Copyright 2014 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <boost/date_time/local_time/local_time_types.hpp>
#include <limits>

#include "bistro/bistro/cron/CrontabItem.h"
#include "bistro/bistro/cron/CrontabSelector.h"

// Add stateful Cron support for more robustness, see README for a design.

namespace folly {
  class dynamic;
}

namespace facebook { namespace bistro { namespace detail_cron {

class EpochCrontabItem : public CrontabItem {
public:
  EpochCrontabItem(const folly::dynamic&, boost::local_time::time_zone_ptr);
  folly::Optional<time_t> findFirstMatch(time_t time_since_utc_epoch)
    const final;
  bool isTimezoneDependent() override { return false; }

private:
  CrontabSelector epoch_sel_;
};

}}}