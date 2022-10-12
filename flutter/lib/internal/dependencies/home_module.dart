import '../../../domain/state/home/home_state.dart';
import '../../../internal/dependencies/repository_module.dart';

class HomeModule {
  static HomeState homeState() {
    return HomeState(
      RepositoryModule.dayRepository(),
    );
  }
}
