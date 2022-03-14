class StorageSystem {
    private int out = 0;
    private List<Integer> diu = new ArrayList<>();
    private Map<Integer, List<Integer>> orders = new HashMap<>();
    private List<Integer> storNum = new ArrayList<>();
    private List<Integer> storPrice = new ArrayList<>();
    private int delay = 0;

    public StorageSystem(int coldStorageNum, int coldStoragePrice,
        int normalStorageNum, int normalStoragePrice, int delay) {
        this.storNum.add(0, coldStorageNum);
        this.storNum.add(1, normalStorageNum);
        this.storPrice.add(0, coldStoragePrice);
        this.storPrice.add(1, normalStoragePrice);
        this.delay = delay;
    }

    public int store(int date, int storageId, int storageType, int storageDays) {
        List<Integer> order = new ArrayList<>();
        update(date);
        int type = storageType;
        if (storNum.get(storageType) <= 0) {
            if (storageType == 0) {
                return -1;
            } else if (storNum.get(0) <= 0) {
                return -1;
            } else {
                type = 0;
            }
        }
        order.add(date);
        order.add(storageDays);
        order.add(type);
        order.add(date + storageDays + delay);
        orders.put(storageId, order);
        storNum.set(type, storNum.get(type) - 1);
        return storageDays * storPrice.get(type);
    }

    public int retrieve(int date, int storageId) {
        update(date);
        if (!orders.containsKey(storageId)) {
            return -1;
        }
        int outDate = date - (orders.get(storageId).get(3) - delay);
        int type = orders.get(storageId).get(2);
        storNum.set(orders.get(storageId).get(2), storNum.get(orders.get(storageId).get(2)) + 1);
        orders.remove(storageId);
        out ++;
        if (outDate > 0) {
            return (outDate * storPrice.get(type));
        }
        return 0;
    }

    public int[] query(int date) {
        update(date);
        int[] nums = new int[3];
        nums[0] = out;
        nums[2] = diu.size();
        nums[1] = orders.size();
        return nums;
    }

    private void update(int date) {
        List<Integer> diuNow = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> order : orders.entrySet()) {
            if (order.getValue().get(3) < date) {
                diuNow.add(order.getKey());
            }
        }
        for (Integer ord : diuNow) {
            storNum.set(orders.get(ord).get(2), storNum.get(orders.get(ord).get(2)) + 1);
            orders.remove(ord);
            diu.add(ord);
        }
    }
}
