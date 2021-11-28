class Solution:
    def trap(self, height: List[int]) -> int:
        def topology_up_down(heights):
            # Find the locations of the maximum
            hmax = max(heights)
            topology_up = []
            for h in heights:
                if h == hmax:
                    topology_up.append(1)
                else:
                    topology_up.append(0)

            topology_down = []
            for h, tup in zip(heights, topology_up):
                topology_down.append(h-tup)

            return topology_up, topology_down

        def get_water_volume(topology):
            topology_up, topology_down = topology_up_down(topology)
            vol_up = get_vol_binary(topology_up)

            if max(topology_down) >= 1:
                vol_down = get_water_volume(topology_down)
            else:
                vol_down = get_vol_binary(topology_down)

            return vol_up + vol_down

        def get_vol_binary(heights):
            def skip_starting_0s(binary_vec):
                if binary_vec and binary_vec[0] == 0:
                    new_vec = skip_starting_0s(binary_vec[1:])
                else:
                    new_vec = binary_vec
                return new_vec

            def skip_starting_0s_it(binary_vec):
                if binary_vec:
                    ind_list = [i for i, x in enumerate(binary_vec) if x]
                    if ind_list == []:
                        new_vec = []
                    else:
                        new_vec = binary_vec[ind_list[0]:]
                else:
                    new_vec = binary_vec
                return new_vec

            def skip_ending_0s(binary_vec):
                if binary_vec and binary_vec[-1] == 0:
                    new_vec = skip_ending_0s(binary_vec[:-1])
                else:
                    new_vec = binary_vec
                return new_vec

            def skip_ending_0s_it(binary_vec):
                if binary_vec:
                    ind_list = [i for i, x in enumerate(binary_vec[::-1]) if x]
                    if ind_list == []:
                        new_vec = []
                    else:
                        new_vec = binary_vec[:len(binary_vec)-ind_list[0]]
                else:
                    new_vec = binary_vec
                return new_vec

            heights_only_valleys = skip_ending_0s_it(skip_starting_0s_it(heights))

            def count_depressions(binary_heights):
                count = 0
                for h in binary_heights:
                    if h == 0:
                        count = count + 1

                return count

            return count_depressions(heights_only_valleys)

        return get_water_volume(height)
