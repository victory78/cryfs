#include "blockstore/implementations/low2highlevel/LowToHighLevelBlockStore.h"
#include "blockstore/implementations/testfake/FakeBlockStore.h"
#include "blockstore/implementations/inmemory/InMemoryBlockStore2.h"
#include "../../testutils/BlockStoreTest.h"
#include <gtest/gtest.h>
#include <cpp-utils/tempfile/TempFile.h>

using ::testing::Test;

using blockstore::BlockStore;
using blockstore::BlockStore2;
using blockstore::lowtohighlevel::LowToHighLevelBlockStore;
using blockstore::testfake::FakeBlockStore;
using blockstore::inmemory::InMemoryBlockStore2;

using cpputils::Data;
using cpputils::DataFixture;
using cpputils::make_unique_ref;
using cpputils::unique_ref;
using cpputils::TempFile;

class LowToHighLevelBlockStoreTestFixture: public BlockStoreTestFixture {
public:
  LowToHighLevelBlockStoreTestFixture() {}

  unique_ref<BlockStore> createBlockStore() override {
    return make_unique_ref<LowToHighLevelBlockStore>(make_unique_ref<InMemoryBlockStore2>());
  }
};

INSTANTIATE_TYPED_TEST_CASE_P(LowToHighLevel, BlockStoreTest, LowToHighLevelBlockStoreTestFixture);
