% Load training and test data
images = [loadMNISTImages('train-images.idx3-ubyte')'; ...
          loadMNISTImages('t10k-images.idx3-ubyte')'];
labels = [loadMNISTLabels('train-labels.idx1-ubyte'); ...
                loadMNISTLabels('t10k-labels.idx1-ubyte')];
            
% Divide data into training and test sets
X_train = images(1:60000, :);
X_test  = images(60001:70000, :);
y_train = labels(1:60000, :);
y_test  = labels(60001:70000, :);

%{
% Find best parameters for training
bestcv = 0;
for log2c = 1:2
  for log2g = -4:-3,
    cmd = ['-v 5 -c ', num2str(2^log2c), ' -g ', num2str(2^log2g), ' -h 1'];
    cv = svmtrain(y_train, X_train, cmd);
    if (cv >= bestcv),
      bestcv = cv; bestc = 2^log2c; bestg = 2^log2g;
    end
    fprintf('%g %g %g (best c=%g, g=%g, rate=%g)\n', log2c, log2g, cv, bestc, bestg, bestcv);
  end
end
C = bestc;
gamma = bestg;
%}
C = 4;
gamma = 0.0625;

% Train for digit recognition
options = ['-c ' num2str(C) ' -g ' num2str(gamma) ' -m 2000 -h 1'];
model = svmtrain(y_train, X_train, options);

% Use test set to check accuracy for training and testing data
[p_train, accuracy_train, ~] = svmpredict(y_train, X_train, model);
[p_test, accuracy_test, ~] = svmpredict(y_test, X_test, model);



