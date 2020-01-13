<?php

$array = [
    [
        'name' => 'A',
        'num' => 12,
    ],
    [
        'name' => 'B',
        'num' => 10,
    ],
    [
        'name' => 'C',
        'num' => 8,
    ],
    [
        'name' => 'D',
        'num' => 5,
    ],
    [
        'name' => 'E',
        'num' => 2,
    ],
];

$array = [
    [
        'name' => 'A',
        'num' => 3,
    ],
    [
        'name' => 'B',
        'num' => 3,
    ],
];

$tasks = ["A", "B", "C", "D", "E", "A", "B", "C", "D", "E"];



foreach ($array as $key => $val) {
    $sum += $val['num'];
}

$class = new Solution();
var_dump($class->leastInterval($tasks, 2));

class Solution
{
    private $num;

    /**
     * @param String[] $tasks
     * @param Integer $n
     * @return Integer
     */
    public function leastInterval($tasks, $n)
    {
        $arrays = $this->build_array($tasks);
        $this->num = $arrays[0]['num'];
        $sum = $this->compute($arrays, $n, count($tasks));
    }


    function build_array($tasks)
    {
        $array = [];
        foreach ($tasks as $key => $task) {
            $array[$task] = [
                'name' => $task,
                'num' => $array[$task]['num'] + 1
            ];
        }
        return array_values($array);
    }

    function compute($array, $n, $sum)
    {
        $array = $this->array_sort($array, 'num', SORT_DESC);
        $m = ($n + 1) * $array[0]['num'] - $n;
        if ($sum <= $m) {
            return $m;
        } else {
            $scrollM = $m;
            foreach ($array as $key => $val) {
                if ($scrollM - $val['num'] >= 0) {
                    unset($array[$key]);
                } else {
                    $array[$key]['num'] = $array[$key]['num'] - $scrollM + ($array[$key]['num'] == $this->num) ? 1 : 0;
                    $sum = $sum - $scrollM;
                    break;
                }
                $scrollM = $scrollM - $val['num'];
                $sum = $sum - $val['num'];
            }
            // echo  "$n, $sum, $m\n";
            // var_dump($array);
            return $this->compute($array, $n, $sum) + $m;
        }
    }


    function array_sort($array, $on, $order = SORT_ASC)
    {
        $new_array = array();
        $sortable_array = array();

        if (count($array) > 0) {
            foreach ($array as $k => $v) {
                if (is_array($v)) {
                    foreach ($v as $k2 => $v2) {
                        if ($k2 == $on) {
                            $sortable_array[$k] = $v2;
                        }
                    }
                } else {
                    $sortable_array[$k] = $v;
                }
            }

            switch ($order) {
                case SORT_ASC:
                    asort($sortable_array);
                    break;
                case SORT_DESC:
                    arsort($sortable_array);
                    break;
            }

            foreach ($sortable_array as $k => $v) {
                array_push($new_array, $array[$k]);
            }
        }

        return $new_array;
    }
}
